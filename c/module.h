#ifndef MODULE_H_
#define MODULE_H_

#define HW_MODULE_INFO_SYM  HMI
#define HW_MODULE_INFO_SYM_AS_STR  "HMI"

typedef struct hw_module_t {
    int id;
    const char *name;
    const char *author;
    void (*print)(const struct hw_module_t* module);
} hw_module;

#endif
