#include <stdio.h>

#include "matrix-functions.h"

int main(){
    int cols;
    int rows;

    // --------------- MENU ---------------

    printf("┌───────────────────────────────────────────────┐\n");
    printf("│  \e[1;36mSVD MATRIX CALCULATOR\e[0m                        │\n");
    printf("├───────────────────────────────────────────────┤\n");
    printf("│ • Computes: U, Σ and V* matrices              │\n");
    printf("│ • Supports both real and complex matrices     │\n");
    printf("│ • Full/compact SVD modes available            │\n");
    printf("├───────────────────────────────────────────────┤\n");
    printf("│ \e[3mLicensed under GPL v3.0 - Open Source Project\e[0m │\n");
    printf("│ Created by \e[1;35mMiquel Estruch Morais\e[0m              │\n");
    printf("└───────────────────────────────────────────────┘\n");

    // --------------- MENU ---------------

    printf("1. Introdueix les columnes de A: ");
    scanf("%d", &cols);
    
    printf("2. Introdueix les files de A: ");
    scanf("%d", &rows);


    Matrix *A = matrix_Constructor(rows, cols);
    matrix_filler(A);
    Matrix *AT = matrix_Traspose(A);

    
    printf("\n MATRIU A:\n");
    matrix_print(A);
    printf("\n MATRIU AT:\n");
    matrix_print(AT);
    

    Matrix *C1 = matrix_Multiplicate(A, AT);
    Matrix *C2 = matrix_Multiplicate(AT, A);

    printf("\n MATRIU C1:\n");
    matrix_print(C1);
    printf("\n MATRIU C2:\n");
    matrix_print(C2);
    

    Matrix *result = matrix_triangulator(A);

    printf("\n MATRIU C2:\n");
    matrix_print(result);

    matrix_Destructor(A);
    matrix_Destructor(AT);
    matrix_Destructor(C1);
    matrix_Destructor(C2);
    matrix_Destructor(result);

}