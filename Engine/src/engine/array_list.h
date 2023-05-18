#pragma once

#include "types.h"

typedef struct array_list {
    size_t len;
    size_t capacity;
    size_t item_size;
    void *items;
} Array_list;

Array_list *array_list_create(size_t item_size, size_t initial_capacity);
size_t array_list_append(Array_list *list, void *items);
void *array_list_get(Array_list *list, size_t index);
u8 array_list_remove(Array_list *list, size_t index);