#include <stdio.h>
#include <stdlib.h>


int main(){
    for (int i = 0; i < 3; i++)
        fork();
    sleep(5);

}

// 2^3 processes created (each process forks on two, so number = 2^n, n - number of forks commands)