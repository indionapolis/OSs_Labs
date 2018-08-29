#include <stdio.h>
#include <memory.h>

void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main() {
    // declare a 'string'
    char str[128];

    printf("Enter two integers: ");

    // get string from user
    gets(str);

    // get x and y values from string
    int x, y;
    sscanf(str, "%i %i", &x, &y);

    printf("original: %i %i\n", x, y);

    // function call
    swap(&x, &y);

    printf("swapped: %i %i\n", x, y);


    return 0;
}

