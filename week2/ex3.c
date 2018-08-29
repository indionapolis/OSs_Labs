#include <stdio.h>
#include <memory.h>

int main(int argc, char *argv[]) {
    // check parameter
    if (argc == 1){
        printf("end of program\n");
        return 1;
    }

    // get n value
    int n;
    sscanf(argv[1], "%i", &n);

    //print string by string with stars +2, spaces -1
    for (int spaces = n-1, stars = 1; spaces >= 0; spaces--, stars+=2){
        for (int i = spaces; i > 0; i--){
            printf(" ");
        }
        for (int i = stars; i > 0; i--){
            printf("*");
        }

        printf("\n");
    }



    return 0;
}