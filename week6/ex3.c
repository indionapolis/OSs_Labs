#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>
#include <string.h>

void handler(int sig)
{
    printf("you hit Ctrl-C\n");
    signal(SIGINT, handler);
}

int main(void)
{
    signal(SIGINT, handler);
    while (1){}
    return 0;
}

