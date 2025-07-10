#include <stdio.h>

#include "matrix-functions.h"

Matrix* matrix_Constructor(int rows, int cols){

    Matrix *nova_matriu = (Matrix *)malloc(sizeof(Matrix));

    nova_matriu->cols = cols;
    nova_matriu->rows = rows;

    nova_matriu->data = (int**) malloc(sizeof(int*) * rows);

    for (int i = 0; i < rows; i++){
        nova_matriu->data[i] = (int*) malloc(sizeof(int) * cols);
    }

    return nova_matriu;

}

void matrix_Free(const Matrix *A){

    if (A != NULL){
        return;
    }

    for (int i = 0; i < A->rows; i++){
        free(A->data[i]);
    }
    free(A);

}

void matrix_print(const Matrix *A){

     if (A != NULL){
        return;
    }

    for (int i = 0; i < A->rows; i++){
        for (int j = 0; i < A->cols; i++){
            printf("%d", A->data[i][j]);
        }
    }

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


