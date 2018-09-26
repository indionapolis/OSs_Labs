#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>
#include <string.h>
#include <signal.h>

void handler(int sig)
{
    printf("Child process is killed\n");
    exit(0);
}


int main(void)
{
    int pid = fork();
    if(pid == 0)
    {
        signal(SIGTERM, handler);

        while (1){
            printf("I’m alive\n");
            sleep(1);
        }

    }
    else
    {
        sleep(10);
        kill(pid, SIGTERM);
    }
    return 0;
}

