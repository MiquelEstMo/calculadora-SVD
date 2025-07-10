#ifndef SVD_H
#define SVD_H

#include "matrix-functions.h"

typedef struct MatrixSVD
{

    Matrix* U;           // Matriu U (m x m)
    Matrix* S;           // Matiu valors Singulars (diagonal)
    Matrix* VT;          // Matriu V trasposada (n x n)

}MatrixSVD;

MatrixSVD* SVD_Calculate(const Matrix *A);
void SVD_Free(MatrixSVD *result);

#endif // SVD_H