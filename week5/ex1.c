#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>

#define NUMBER_OF_THREADS 10


pthread_t threads[NUMBER_OF_THREADS];

void *print_hello_world(void *tid) {
    //force the order to be strictly
    if (tid > 0){
        pthread_join(threads[(int)tid-1], NULL);
    }
    printf("Hello World. Greetings from thread %d\n", tid);
    pthread_exit(NULL);
}


int main(int argc, char *argv[]) {
    for(int i=0; i < NUMBER_OF_THREADS; i++) {
        printf("Main is creating thread %d\n", i);
        pthread_create(&threads[i], NULL, print_hello_world, (void *)i);
    }

    sleep(3);
    exit(NULL);
}