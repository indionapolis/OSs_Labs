#include <stdlib.h>
#include <stdio.h>


int main(){
    //Allows you to generate random number
    srand(453);

    // Allows user to specify the original array size, stored in variable n1.
    printf("Enter original array size:");
    int n1=0;
    scanf("%d",&n1);

    //Create a new array of n1 ints
    int* a1 = malloc(n1*sizeof(int));
    int i;
    for(i=0; i<n1; i++){
        //Set each value in a1 to 100
        a1[i] = 100;

        //Print each element out (to make sure things look right)
        printf("%d ", a1[i]);
    }

    //User specifies the new array size, stored in variable n2.
    printf("\nEnter new array size: ");
    int n2=0;
    scanf("%d",&n2);

    //allocate new memory
    int* tmp = calloc(n2, sizeof(int));

    for(i=0; i < (n1>n2 ? n2:n1); i++){
        tmp[i] = a1[i];
    }

    free(a1);
    a1 = tmp;

    for(i=0; i < n2; i++){
        //Print each element out (to make sure things look right)
        printf("%d ", a1[i]);
    }
    printf("\n");

    //Done with array now, done with program :D

    return 0;
}