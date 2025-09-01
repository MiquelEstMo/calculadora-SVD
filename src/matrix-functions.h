#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

typedef struct Matrix
{
    
    double** data;     // Dades de la matriu (files x columnes)
    int cols;       // Nombre de columnes
    int rows;       // Nombre de files

}Matrix;


Matrix* matrix_Constructor(int rows, int cols);
void matrix_filler(Matrix* matrix);
void matrix_Destructor(Matrix *A);

void matrix_print(const Matrix *A);

Matrix* matrix_Multiplicate(const Matrix *A, const Matrix *B);
Matrix* matrix_Traspose(const Matrix *A);
Matrix* matrix_Copy(const Matrix *A);
void matrix_swap_rows(Matrix *A, int row_A, int row_B);
Matrix* matrix_triangulator(const Matrix *A);
Matrix* matrix_Inverse(const Matrix *A);
double matrix_normalize(const Matrix *A);

bool is_matrix_square(const Matrix *A);
bool is_matrix_symetric(const Matrix *A);

#endif