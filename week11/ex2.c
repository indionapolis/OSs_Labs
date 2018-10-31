//
// Created by Pavel on 31/10/2018.
//

#include <string.h>
#include <stdio.h>
#include <zconf.h>

int main(){
    char* string = "Hello";
    for (int i = 0; i < strlen(string); i++){
        printf("%c", string[i]);
        sleep(1);
    }
}