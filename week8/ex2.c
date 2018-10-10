#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>

#define SIZE (10*1024*1024)

int main() {
    while (1){
        char *data;
        data = (char *)malloc(SIZE);
        for (int i = SIZE-1; i >= 0; i--){
            data[i] = (char) 0;
        }
        sleep(1);
    }

    return 0;
}