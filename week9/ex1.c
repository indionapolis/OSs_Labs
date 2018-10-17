#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int main(int argc, char* argv[]) {
    struct frame {
        bool empty;
        bool referenced;
        unsigned long lifespan;
        int number;
    };

    unsigned long left_bit = (unsigned long) 1 << 31;

    int frames_number = 0;

    char *path = "/Users/Pavel/programs/OSs/input.txt";

    FILE *ptr_file = fopen(path, "r");

    if (ptr_file == NULL){
        printf("Could not open file %s\n", path);
        return 1;
    }


    printf("Enter the number of page frames: ");
    scanf("%d", &frames_number);

    struct frame memory[frames_number];
    //initial memory state
    for (int i = 0; i < frames_number; i++){
        memory[i].empty = true;
        memory[i].referenced = false;
        memory[i].lifespan = 0;
        memory[i].number = -1;
    }

    // read file

    int current_page_number;
    int hit = 0;
    int miss = 0;

    while (fscanf(ptr_file, "%d", &current_page_number) != -1){
        //printf("%d\n", current_page_number);

        //check if page in memory
        bool flag = false;
        for (int i = 0; i < frames_number; i++){
            if (memory[i].number == current_page_number){
                memory[i].referenced = true;
                flag = true;
                break;
            }
        }

        //if page not in memory
        if (flag == false){
            miss++;
            flag = false;
            for (int i = 0; i < frames_number; i++){
                if (memory[i].empty == true){
                    memory[i].empty = false;
                    memory[i].referenced = true;
                    memory[i].lifespan = 0;
                    memory[i].number = current_page_number;
                    flag = true;
                    break;
                }
            }
            //if no empty space left
            if(flag == false){

                unsigned long min = left_bit + 1;
                struct frame *frame_to_swapp = NULL;
                for (int i = 0; i < frames_number; i++){
                    if (memory[i].lifespan < min){
                        min = memory[i].lifespan;
                        frame_to_swapp = &memory[i];
                    }
                }
                if (frame_to_swapp == NULL){
                    frame_to_swapp = &memory[0];
                }
                frame_to_swapp->empty = false;
                frame_to_swapp->referenced = true;
                frame_to_swapp->lifespan = 0;
                frame_to_swapp->number = current_page_number;
            }
        } else {
            hit++;
        }


        //update lifespan
        for (int i = 0; i < frames_number; i++){
            memory[i].lifespan = memory[i].lifespan >> 1;
            if (memory[i].referenced == true){
                memory[i].referenced = false;
                memory[i].lifespan = memory[i].lifespan | left_bit;
            }
        }
    }

    for (int i = 0; i < frames_number; i++){
        //printf("%d\n", memory[i].number);
    }

    printf("%d %d", hit, miss);
    return 0;
}