#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <zconf.h>

//
// Created by Pavel on 31/10/2018.
//
int main(){
    char* new_string = "This is a nice day";
    int fd = open("/Users/Pavel/programs/OSs/git/week11/ex1.txt", O_RDWR);
    size_t size = strlen(new_string);

    lseek(fd, size-1, SEEK_SET);

    write(fd, "r", 1);

    char *string = mmap(NULL, size+1, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

    memcpy(string, new_string, size);
    munmap(string, size+1);

    close(fd);

    return 0;
}
