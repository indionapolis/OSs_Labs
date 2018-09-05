#include <stdio.h>
#define SIZE 10

void bubble_sort(int* array, int size);

void print_array(int* array, int size);

int main(){
    // declare array of integers
    int array[SIZE] = {1, 3, 2, 7, 8, 9, 4, 6, 5, 0};
    print_array(array, SIZE);
    bubble_sort(array, SIZE);
    print_array(array, SIZE);

}

void bubble_sort(int* array, int size){
    for (int i = size-1; i >= 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (array[j]>array[j+1]){
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
}

void print_array(int* array, int size){
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}