#include "vm.h"

vm_t *vm_new() {
    vm_t *vm = malloc(sizeof(vm_t));
    if (!vm) return NULL;
    vm->frames = stack_new(8);
    vm->objects = stack_new(8);
    return vm;
}

void vm_free(vm_t *vm) {
    if (!vm) return NULL;
    stack_free(vm->frames);
    stack_free(vm->objects);
    free(vm);
}