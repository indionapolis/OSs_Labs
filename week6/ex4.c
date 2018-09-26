#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>
#include <string.h>

void handler0(int sig)
{
    printf("from SIGKILL\n");
    signal(SIGKILL, handler0);
}

void handler1(int sig)
{
    printf("from SIGSTOP\n");
    signal(SIGSTOP, handler1);
}

void handler2(int sig)
{
    printf("from SIGUSR1\n");
    signal(SIGUSR1, handler2);
}


int main(void)
{
    signal(SIGKILL, handler0);
    signal(SIGSTOP, handler1);
    signal(SIGUSR1, handler2);
    while (1){}
    return 0;
}

