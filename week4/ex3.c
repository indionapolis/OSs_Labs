#include <stdio.h>
#include <stdlib.h>

#define MAX_LIMIT 120

static char str[MAX_LIMIT];


int main(){
    while (1){
        printf("$: ");
        fgets(str, MAX_LIMIT, stdin);
        system(str);
    }
}
