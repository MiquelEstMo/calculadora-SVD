#include <stdio.h>
#include <stdlib.h>

#include "matrix-functions.h"

Matrix* matrix_Constructor(int rows, int cols){

    Matrix *new_matrix = (Matrix *)malloc(sizeof(Matrix));

    new_matrix->cols = cols;
    new_matrix->rows = rows;

    new_matrix->data = (int**) malloc(sizeof(int*) * rows);

    for (int i = 0; i < rows; i++){
        new_matrix->data[i] = (int*) malloc(sizeof(int) * cols);
    }

    printf("[SUCCESS!!]: Matrix created succesfully\n");

    return new_matrix;

}

void matrix_filler(Matrix* matrix){

    int data = 0;

    for (int i = 0; i < matrix->rows; i++){

        for (int j = 0; j < matrix->cols; j++){

            printf("Insert value [%d][%d]: ", i, j );
            scanf("%d", &data);

            matrix->data[i][j] = data;

        }

    }

    printf("\n");
}

void matrix_Destructor(Matrix* matrix) {

    if (matrix != NULL) {

        for (int i = 0; i < matrix->rows; i++) {
            free(matrix->data[i]);
        }

        free(matrix->data);
        free(matrix);
    }
}

void matrix_print(const Matrix *A){
    if (A == NULL){
        printf("[ERROR!]: Matrix is NULL\n");
        return;
    }
    
    for (int i = 0; i < A->rows; i++){
        for (int j = 0; j < A->cols; j++){
            printf("%4d ", A->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

Matrix* matrix_Multiplicate(const Matrix *A, const Matrix *B){

    if (A->cols != B->rows) {
        printf("[ERROR!]: Dimensiones incompatibles\n");
        return NULL;
    }

    Matrix *result = matrix_Constructor(A->rows, B->cols);
    if (!result) return NULL;

    for(int i = 0; i < A->rows; i++){
        for(int j = 0; j < B->cols; j++){
            result->data[i][j] = 0;
            for (int k = 0; k < A->cols; k++){
                result->data[i][j] += A->data[i][k] * B->data[k][j];
            }
        }
    }

    return result;

}


