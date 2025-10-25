#include "arraylist.h"
#include<stdio.h>
#include<stdlib.h>

int al_init(ArrayList *list, size_t initial_capicity) {
    if(initial_capicity == 0) initial_capicity = 2;
    list->data = (int*)malloc(initial_capicity * sizeof(int));
    if(!list->data) return -1;
    list->size = 0;
    list->capacity = initial_capicity;
    return 0;
}

static int al_grow(ArrayList *list) {
    size_t new_cap = list->capacity ? list->capacity * 2 : 2;
    int *p = (int*)realloc(list->data, new_cap * sizeof(int));
    if(!p) return -1;
    list->data = p;
    list->capacity = new_cap;
    return 0;
}

int al_add(ArrayList *list, int value) {
    if(list->size == list->capacity) {
        if(al_grow(list) != 0) return -1;
    }
    list->data[list->size++] = value;
    return 0;
}

int al_get(const ArrayList *list, size_t index, int *out_value) {
    if(index >= list->size) return -1;
    if(out_value) *out_value = list->data[index];
    return 0;
}

void al_free(ArrayList *list) {
    if(!list) return;
    free(list->data);
    list->data = NULL;
    list->size = 0;
    list->capacity = 0;
}