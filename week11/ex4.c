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
    int fd = open("/Users/Pavel/programs/OSs/git/week11/ex1.txt", O_RDWR);
    fopen("/Users/Pavel/programs/OSs/git/week11/ex1.memcpy.txt", "w");
    int fd2 = open("/Users/Pavel/programs/OSs/git/week11/ex1.memcpy.txt", O_RDWR);

    struct stat fs;
    fstat(fd,&fs);

    printf("%d", fs.st_size);

    lseek(fd2, fs.st_size-1, SEEK_SET);
    write(fd2, "r", 1);

    char *string = mmap(NULL, fs.st_size+1, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    char *string2 = mmap(NULL, fs.st_size+1, PROT_READ|PROT_WRITE, MAP_SHARED, fd2, 0);

    memcpy(string2, string, fs.st_size);
    munmap(string, fs.st_size+1);
    munmap(string2, fs.st_size+1);

    close(fd);
    close(fd2);

    return 0;
}

