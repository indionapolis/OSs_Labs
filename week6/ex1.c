#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>
#include <string.h>


int main(int argc, char *argv[]) {

    int     pipe_buff[2], nbytes;
    char    string0[] = "Hello, world!\n\0";
    char    string1[80];

    pipe(pipe_buff);
    write(pipe_buff[1], string0, (strlen(string0)+1));
    nbytes = read(pipe_buff[0], string1, sizeof(string1));
    printf("Received string: %s \nLength: %d", string1, nbytes);

    return 0;

}