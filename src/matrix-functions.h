#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>

typedef struct Matrix
{
    
    int** data;     // Dades de la matriu (files x columnes)
    int cols;       // Nombre de columnes
    int rows;       // Nombre de files

}Matrix;


Matrix* matrix_Constructor(int rows, int cols);
void matrix_Free(const Matrix *A);

void matrix_print(const Matrix *A);

Matrix* matrix_Multiplicate(const Matrix *A, const Matrix *B);
Matrix* matrix_Traspose(const Matrix *A);
Matrix* matrix_Inverse(const Matrix *A);
double matrix_normalize(const Matrix *A);

bool is_matrix_square(const Matrix *A);
bool is_matrix_symetric(const Matrix *A);

#endif