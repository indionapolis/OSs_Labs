#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LIMIT 120

static char* argv[512];
static char str[MAX_LIMIT];


static void pars(char *cmd);


int main(){
    int pid;

    while (1) {
        printf("$: ");

        //get command from input
        fgets(str, MAX_LIMIT, stdin);

        //set arguments for execvp
        pars(str);

        //get two processes (one in bg)
        pid = fork();

        if (pid == 0) {
            //execute command
            execvp(argv[0], argv);
        }
    }
}


void pars(char *cmd)
{

    //split arguments by space
    char* rest = strchr(cmd, ' ');
    int i = 0;

    while(rest != NULL) {

        rest[0] = '\0';
        argv[i] = cmd;
        ++i;
        cmd = rest + 1;
        rest = strchr(cmd, ' ');
    }

    if (cmd[0] != '\0') {
        argv[i] = cmd;
        rest = strchr(cmd, '\n');
        rest[0] = '\0';
        ++i;
    }

    argv[i] = NULL;
}