#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void* my_realloc(void* ptr, size_t size){
    if (!size){
        free(ptr);
        return NULL;
    }
    if (!ptr){
        return malloc(size);
    }

    void* new_ptr = malloc(size);

    memcpy(new_ptr, ptr, size);
    free(ptr);

    return new_ptr;
}


int main(){
    int* block = malloc(5* sizeof(int));

    block = my_realloc(block, 100000);

    my_realloc(block, 0);

    my_realloc(NULL, 5);


    return 0;
}