#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];

int current_size = 0;

pthread_t consumer;
pthread_t producer;


void *consume();


void *produce() {
    while (1){
        if (current_size > BUFFER_SIZE - 1){
            printf("producer sleep\n");
        }
        buffer[current_size] = rand();
        current_size++;
    }
}


void *consume() {
    while (1){
        if (current_size < 0){
            printf("consumer sleep\n");
        }
        printf("%d\n",buffer[current_size]);
        current_size--;
    }
}


int main(int argc, char *argv[]) {
    pthread_create(&producer, NULL, produce, (void *)0);
    pthread_create(&consumer, NULL, consume, (void *)0);

    sleep(50);
    exit(NULL);
}