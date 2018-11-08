//
// Created by Pavel on 07/11/2018.
//

#include <zconf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    char* buffer = malloc(sizeof(char)*20);
    FILE *file = fopen("/Users/Pavel/programs/OSs/git/week12/ex1.txt", "w");
    int fd = open("/dev/random", O_RDONLY);
    read(fd, buffer, sizeof(char)*20);
    fprintf(file, "%s", buffer);
    close(fd);
    fclose(file);
    return 0;
}