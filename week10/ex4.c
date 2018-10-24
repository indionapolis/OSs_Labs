//
// Created by Pavel on 24/10/2018.
//

#include <stdio.h>
#include <dirent.h>
#include <memory.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

void print_matches(char *name, __uint64_t ino, char *base_address){
    DIR *dirp = opendir(base_address);

    struct dirent *dp;

    printf("%s:\n", name);

    while ((dp = readdir(dirp)) != NULL) {
        if (ino == dp->d_ino){
            if (strcmp(dp->d_name, name))
                printf("    %s\n", dp->d_name);
        }
    } 
    closedir(dirp);
}

int main(int argc, char* argv[]){
    char *base_address = "/Users/Pavel/programs/OSs/git/week10/tmp/";

    DIR *dirp = opendir(base_address);
    if (dirp == NULL) {
        return 1;
    }

    struct dirent *dp;

    struct stat *info = malloc(sizeof(struct stat));

    while ((dp = readdir(dirp)) != NULL) {
        char full_address[90];
        strcpy(full_address, base_address);
        strcat(full_address, dp->d_name);
        stat(full_address, info);

        if (strcmp(dp->d_name, ".") & strcmp(dp->d_name, "..")){
            if (info->st_nlink >= 2){
                print_matches(dp->d_name, dp->d_ino, base_address);
            }
        }
    } 

    closedir(dirp);
    return 0;
}