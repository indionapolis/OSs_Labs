#include <stdio.h>
#include <memory.h>
#define min(a, b) ((a) < (b)) ? (a) : (b)

// second program argument
//
// #1
//       *
//      ***
//     *****
//    *******
//   *********
//  ***********
// *************
//
//
// #2
// *
// **
// ***
// ****
// *****
// ******
// *******
//
// #3
// *
// **
// ***
// ****
// ***
// **
// *
//
// #4
// *******
// *******
// *******
// *******
// *******
// *******
// *******


void right_side_up_triangle(int n){

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
}

void right_triangle(int n){

    //print string by string
    for (int stars = 1; stars <= n; stars++){
        for (int i = stars; i > 0; i--){
            printf("*");
        }

        printf("\n");
    }
}

void side_triangle(int n){

    //print string by string
    for (int start = 1, finish = n; start <= n; start++, finish--){
        for (int i = min(start, finish); i > 0; i--){
            printf("*");
        }

        printf("\n");
    }
}

void rectangle(int n){

    //print string by string
    for (int start = 1; start <= n; start++){
        for (int i = 1; i <= n; i++){
            printf("*");
        }

        printf("\n");
    }
}


int main(int argc, char *argv[]) {
    // check parameters
    if (argc == 1){
        printf("end of program\n");
        return 1;
    }

    // get n value
    int n;
    sscanf(argv[1], "%i", &n);
    // get type
    int type;
    sscanf(argv[2], "%i", &type);

    // choose type of picture
    switch (type){
        case 1:
            right_side_up_triangle(n);
            break;
        case 2:
            right_triangle(n);
            break;
        case 3:
            side_triangle(n);
            break;
        case 4:
            rectangle(n);
            break;
    }



    return 0;
}

