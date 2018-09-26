#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>
#include <string.h>
#include <signal.h>

void handler(int sig)
{
    printf("2nd child process is killed\n");
    exit(0);
}


int main(void)
{
    int     pipe_buff[2];
    char    string0[] = "Hello, world!\n\0";
    char    string1[80];

    pipe(pipe_buff);

    int pid1 = fork();
    if(pid1 == 0)
    {
        printf("1st child here!\n");

        int _2nd_child_pid;

        close(pipe_buff[1]);
        read(pipe_buff[0], &_2nd_child_pid, sizeof(_2nd_child_pid));
        printf("1st child got _2nd_child_pid! (%d)\n", _2nd_child_pid);

        sleep(3);

        kill(_2nd_child_pid, SIGSTOP);
        printf("1st child stopped 2nd!\n");

        while (1){
            printf("I’m alive 1\n");
            sleep(2);
        }

    }
    else
    {
        int pid2 = fork();
        if(pid2 == 0)
        {
            signal(SIGSTOP, handler);
            printf("2nd child here!\n");
            while (1){
                printf("I’m alive 2\n");
                sleep(2);
            }

        }
        else
        {

            int status;
            sleep(3);

            close(pipe_buff[0]);
            write(pipe_buff[1], &pid2, sizeof(pid2));

            printf("Parent what 2nd child!\n");
            waitpid(pid2, &status, 0);


            printf("Parent's done\n");
            exit(0);
        }
    }
}

