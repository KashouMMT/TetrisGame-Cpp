#include<stdio.h>
#include<stdlib.h>

#include "matrix.h"

int **init_matrix(int rows, int cols) {

    int **matrix = malloc(rows * sizeof(int*));
    if(!matrix) {
        fprintf(stderr, "Memory allocation failed for matrix rows.\n");
        exit(1);
    }
    for(int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        if(matrix[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for matrix cols.\n");
            for(int k = 0; k < rows; k++) {
                free(matrix[k]);
            }
            free(matrix);
            exit(1);
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }

    return matrix;
}

void **update_matrix_index(int **matrix,int row, int col) {
    if(matrix) matrix[row][col] = 1;
}

void free_matrix(int **matrix,int rows) {
    if(!matrix) return;
    for(int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void display_matrix(int **matrix,int rows, int cols) {
    printf("  /\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n<!====================!>\n   ");
    for(int j = 0; j < cols; j++){ 
        printf("%d ",j);
    }
    printf("\n");
    for(int i = 0; i < rows; i ++) {
        printf(" |");
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] == 1) {
                printf("[]",matrix[i][j]);
            } else {
                printf(" .",matrix[i][j]);
            }
        }
        printf("|\n");
    }
    printf("<!====================!>\n  \\/\\/\\/\\/\\/\\/\\/\\/\\/\\/");
}