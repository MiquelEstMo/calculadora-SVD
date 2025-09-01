#include "matrix-functions.h"

Matrix *SVD(Matrix *A){

    // Pas 1: Calcular C1 i C2

    Matrix *AT = matrix_Traspose(A);

    Matrix *C1 = matrix_Multiplicate(A, AT);
    Matrix *C2 = matrix_Multiplicate(AT, A);

    printf("\n MATRIU C1:\n");
    matrix_print(C1);
    printf("\n MATRIU C2:\n");
    matrix_print(C2);

    
}