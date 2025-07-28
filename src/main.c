#include <stdio.h>

#include "matrix-functions.h"

int main(){
    int cols;
    int rows;

    // --------------- MENU ---------------

    printf("┌───────────────────────────────────────────────┐\n");
    printf("│  \033[1;36mSVD MATRIX CALCULATOR\033[0m                        │\n");
    printf("├───────────────────────────────────────────────┤\n");
    printf("│ • Computes: U, Σ and V* matrices              │\n");
    printf("│ • Supports both real and complex matrices     │\n");
    printf("│ • Full/compact SVD modes available            │\n");
    printf("├───────────────────────────────────────────────┤\n");
    printf("│ \033[3mLicensed under GPL v3.0 - Open Source Project\033[0m │\n");
    printf("│ Created by \033[1;33mMiquel Estruch Morais\033[0m              │\n");
    printf("└───────────────────────────────────────────────┘\n");

    // --------------- MENU ---------------

    printf("1. Introdueix columnes: ");
    scanf("%d", &cols);
    
    printf("2. Introdueix files: ");
    scanf("%d", &rows);


    Matrix *A = matrix_Constructor(rows, cols);
    matrix_filler(A);
    

    matrix_print(A);
    matrix_Destructor(A);

}