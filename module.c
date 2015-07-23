#include <stdio.h>
#include "module.h"

void test_print(const struct hw_module_t* module)
{
    printf("module.so id:%d name:%s author:%s\n", module->id, module->name, module->author);
}

hw_module HW_MODULE_INFO_SYM = {
    .id = 1,
    .name = "the test module",
    .author = "fang",
    .print = test_print
};


