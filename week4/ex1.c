#include <stdio.h>
#include <zconf.h>


int main(){
    int n;

    if (fork() == 0){
        printf("Hello from child [%d - %d]\n", getpid(), n);
    }
    else{
        printf("Hello from parent [%d - %d]\n", getpid(), n);
    }
}

// n - has the same address in both cases, because child process is exact copy of parent process