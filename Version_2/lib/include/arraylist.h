#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include<stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} ArrayList;

int  al_init(ArrayList *list, size_t initial_capacity);
int  al_add(ArrayList *list, int value);
int  al_get(const ArrayList *list, size_t index, int *out_value);
void al_free(ArrayList *list);

#ifdef __cplusplus
}
#endif

#endif