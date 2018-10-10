#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>

#define SIZE (10*1024*1024)

int main() {
    int n = 10;
    while (n){
        char *data;
        data = (char *)malloc(SIZE);
        for (int i = SIZE-1; i >= 0; i--){
            data[i] = (char) 0;
        }

        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        printf("%d\n", usage.ru_maxrss);

        sleep(1);
        n--;
    }

    return 0;
}