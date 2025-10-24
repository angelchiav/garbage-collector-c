#include <stdio.h>
#include "stack.h"

void stack_push(stack_t *stack, void *obj) {
    if (stack->count == stack->capacity) {
        stack->capacity *= 2;
        stack->data = realloc(stack->data, stack->capacity * sizeof(void *));
        if (stack->data == NULL) {
            exit(1);
        }
    }
    stack->data[stack->count] = obj;
    stack->count++;

    return;
}

void *stack_pop(stack_t *stack) {
    if (stack->count == 0) {
        return NULL;
    }

    stack->count--;
    return stack->data[stack->count];
}

void stack_free(stack_t *stack) {
    if (stack == NULL) {
        return;
    }

    free(stack);
}

void stack_remove_nulls(stack_t *stack) {
    size_t counter = 0;

    for (size_t i = 0; i < stack->count; i++) {
        if (stack->data[i] != NULL) {
            stack->data[counter++] = stack->data[i];
        }
    }
    
    stack->count = counter;

    for (size_t i = counter; i < stack->capacity; i++) {
        stack->data[i] = NULL;
    }
}

stack_t *stack_new(size_t capacity) {
    stack_t *stack = malloc(sizeof(stack_t));
    if (stack == NULL) {
        return NULL;
    }

    stack->count = 0;
    stack->capacity = capacity;
    stack->data = malloc(stack->capacity * sizeof(void *));
    if (stack->data == NULL) {
        free(stack);
        return NULL;
    }
    return stack;
}

