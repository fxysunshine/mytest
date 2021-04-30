#include <stdio.h>
#include <errno.h>
#include <dlfcn.h>
#include <unistd.h>
#include "module.h"

int main()
{
    int status = -1;
    void *handle;
    struct hw_module_t *hmi;
    char file_path_getcwd[128];
    char path[256];

    getcwd(file_path_getcwd, 128);
    sprintf(path, "%s/module.so", file_path_getcwd);
    printf("start open the module.so:%s\n", path);
    handle = dlopen(path, RTLD_NOW);
    if (handle == NULL) {
        char const *err_str = dlerror();
        printf("load: module=%s\n%s\n", path, err_str?err_str:"unknown");
        status = -EINVAL;
        goto done;
    }

    const char *sym = HW_MODULE_INFO_SYM_AS_STR;
    hmi = (struct hw_module_t *)dlsym(handle, sym);
    if (hmi == NULL) {
        printf("load: couldn't find symbol %s\n", sym);
        status = -EINVAL;
        goto done;
    }

    /* success */
    status = 0;

done:
    if (status != 0) {
        hmi = NULL;
        if (handle != NULL) {
            dlclose(handle);
            handle = NULL;
        }
    } else {
        printf("loaded path=%s id:%d name:%s author:%s\n", path, hmi->id, hmi->name, hmi->author);
        hmi->print(hmi);
        dlclose(handle);
        printf("module.so closed\n");
        handle = NULL;
    }

    return status;
}
