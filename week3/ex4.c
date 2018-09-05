#include <stdio.h>
#define SIZE 10

void quicksort(int list[], int start, int tail);

void print_array(int* array, int size);

int main(){
    // declare array of integers
    int array[SIZE] = {1, 3, 2, 7, 8, 9, 4, 6, 5, 0};
    print_array(array, SIZE);
    quicksort(array, 0, SIZE);
    print_array(array, SIZE);

}


void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(int list[], int start, int tail)
{
    int key,i,j,k;
    if( start < tail)
    {
        k = start;
        swap(&list[start], &list[k]);
        key = list[start];
        i = start+1;
        j = tail;
        while(i <= j)
        {
            while((i <= tail) && (list[i] <= key))
                i++;
            while((j >= start) && (list[j] > key))
                j--;
            if( i < j)
                swap(&list[i],&list[j]);
        }
        /* swap two elements */
        swap(&list[start],&list[j]);

        /* recursively sort the lesser list */
        quicksort(list,start,j-1);
        quicksort(list,j+1,tail);
    }
}


void print_array(int* array, int size){
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}