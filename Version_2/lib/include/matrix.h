#ifndef MATRIX_H
#define MATRIX_H

#include<stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

int **init_matrix(int rows, int cols);
void free_matrix(int **matrix,int rows);
void display_matrix(int **matrix,int rows, int cols);
void **update_matrix_index(int **matrix,int row, int col);

#ifdef __cplusplus
}
#endif

#endif