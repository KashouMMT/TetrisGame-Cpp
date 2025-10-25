#include<stdio.h>

#include "arraylist.h"

int main()
{
    ArrayList list;
    if(al_init(&list, 4) !=0 ) {
        fprintf(stderr, "Failed to init ArrayList\n");
        return 1;
    }

    for(int i = 0; i < 10; i++) {
        if(al_add(&list,i * 10) != 0 ) {
            fprintf(stderr, "Failed to add element\n");
            al_free(&list);
            return 1;
        }
    }

    for(size_t i =0; i < list.size; i++) {
        int v;
        al_get(&list,i, &v);
        printf("%d",v);
    }
    printf("\n");

    al_free(&list);

    return 0;
}