//
// Created by Pavel on 14/11/2018.
//

// input format:
// E - existing resource vector int[]
//
// A - available resource vector int[]
//
// C - current allocation matrix int[][]
//
// R - request matrix int[][]

#include <stdio.h>
#include <stdlib.h>

void print_matrix(int** matrix, int m, int n){
    FILE* file = fopen("/Users/Pavel/programs/OSs/git/week13/output_dl.txt", "w");
    printf("\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

int main(){
    FILE* file = fopen("/Users/Pavel/programs/OSs/git/week13/input_dl.txt", "r");

    char buff;
    int n = 0;

    //find len of first vector
    while (1){
        if (fscanf(file, "%c", &buff) == -1)
            break;

        if (buff == '\n'){
            fseek(file, 0, SEEK_SET);
            n += 1;
            break;
        }
        if (buff == ' '){
            n += 1;
            continue;
        }
    }

    //prepare E and A vectors
    fseek(file, 0, SEEK_SET);
    int* E = (int*)malloc(n * sizeof(int));
    int* A = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        fscanf(file, "%d", &E[i]);
    }

    for (int i = 0; i < n; i++){
        fscanf(file, "%d", &A[i]);
    }

    //skip new lines
    fscanf(file, "%c", &buff);
    fscanf(file, "%c", &buff);

    //get beginning of matrix
    int matrix_start = (int) ftell(file);

    //find number of rows in C
    int flag = 0;
    int m = 0;
    while (1){
        if (fscanf(file, "%c", &buff) == -1)
            break;
        if (buff == '\n'){
            if (flag){
                break;
            }
            flag = 1;
            m++;
        }else{
            flag = 0;
        }
    }


    //go before the matrix
    fseek(file, matrix_start, SEEK_SET);


    //read C matrix
    int** C = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++){
        C[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            fscanf(file, "%d", &C[i][j]);
        }
    }



    //read R matrix
    int** R = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++){
        R[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            fscanf(file, "%d", &R[i][j]);
        }
    }

    //end of input
    fclose(file);


    //deadlock detection algorithm
    int check = 0;
    int z = 0;
    while (1){
        for (int i = 0; i < m; i++){
            flag = 0;
            //check if we can process all requests of one process
            for (int j = 0; j < n; j++){
                if (R[i][j] <= A[j]){
                    flag += 1;
                    z += R[i][j];
                }
            }
            //get resources back
            if (flag == n && z != 0){
                check = 1;
                for (int j = 0; j < n; j++){
                    A[j] += C[i][j];
                    C[i][j] = 0;
                    R[i][j] = 0;
                }
            }
            z = 0;
        }
        //if no changes in current iteration (deadlock ar all processes satisfied)
        if (check == 0) {
            break;
        }
        check = 0;
    }

    //print matrix back to file
    print_matrix(R, m, n);

    return 0;
}