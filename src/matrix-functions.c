#include "matrix-functions.h"

Matrix *matrix_Constructor(int rows, int cols)
{

    Matrix *new_matrix = (Matrix *)malloc(sizeof(Matrix));

    new_matrix->cols = cols;
    new_matrix->rows = rows;

    new_matrix->data = (double **)malloc(sizeof(double *) * rows);

    for (int i = 0; i < rows; i++)
    {
        new_matrix->data[i] = (double *)malloc(sizeof(double) * cols);
    }

    printf("[SUCCESS!!]: Matrix created succesfully\n");

    return new_matrix;
}

void matrix_filler(Matrix *matrix)
{

    int data = 0;

    for (int i = 0; i < matrix->rows; i++)
    {

        for (int j = 0; j < matrix->cols; j++)
        {

            printf("Insert value [%d][%d]: ", i, j);
            scanf("%d", &data);

            matrix->data[i][j] = data;
        }
    }

    printf("\n");
}

void matrix_Destructor(Matrix *matrix)
{

    if (matrix != NULL)
    {

        for (int i = 0; i < matrix->rows; i++)
        {
            free(matrix->data[i]);
        }

        free(matrix->data);
        free(matrix);
    }
}

void matrix_print(const Matrix *A)
{
    if (A == NULL)
    {
        printf("[ERROR!]: Matrix is NULL\n");
        return;
    }

    for (int i = 0; i < A->rows; i++)
    {
        for (int j = 0; j < A->cols; j++)
        {
            printf("%4lf ", A->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

Matrix *matrix_Multiplicate(const Matrix *A, const Matrix *B)
{

    if (A->cols != B->rows)
    {
        printf("[ERROR!]: Dimensiones incompatibles\n");
        return NULL;
    }

    Matrix *result = matrix_Constructor(A->rows, B->cols);
    if (!result)
        return NULL;

    for (int i = 0; i < A->rows; i++)
    {
        for (int j = 0; j < B->cols; j++)
        {
            result->data[i][j] = 0;
            for (int k = 0; k < A->cols; k++)
            {
                result->data[i][j] += A->data[i][k] * B->data[k][j];
            }
        }
    }

    return result;
}

Matrix *matrix_Traspose(const Matrix *A)
{

    Matrix *AT = matrix_Constructor(A->cols, A->rows);

    for (int i = 0; i < A->cols; i++)
    {
        for (int j = 0; j < A->rows; j++)
        {
            AT->data[i][j] = A->data[j][i];
        }
    }

    return AT;
}

Matrix *matrix_Copy(const Matrix *A)
{

    if (A == NULL)
    {
        printf("[ERROR!]: No matrix aviable.");
        return NULL;
    }

    Matrix *copy = matrix_Constructor(A->rows, A->cols);

    for (int i = 0; i < A->rows; i++)
    {
        for (int j = 0; j < A->cols; j++)
        {
            copy->data[i][j] = A->data[i][j];
        }
    }

    return copy;
}

// Función corregida para intercambiar filas - MODIFICA la matriz directamente
void matrix_swap_rows(Matrix *A, int row_A, int row_B)
{
    if (A == NULL || row_A == row_B)
        return;

    double *temp = A->data[row_A];
    A->data[row_A] = A->data[row_B];
    A->data[row_B] = temp;
}

// Función de triangularización corregida
Matrix *matrix_triangulator(const Matrix *A)
{
    const double EPSILON = 1e-10;
    Matrix *result = matrix_Copy(A);

    // Ordenar matriz por primera columna (de mayor a menor)
    for (int i = 0; i < result->rows - 1; i++)
    {
        for (int j = 0; j < result->rows - i - 1; j++)
        {
            if (result->data[j][0] < result->data[j + 1][0])
            {
                matrix_swap_rows(result, j, j + 1); // Usar la función de intercambio
            }
        }
    }

    // Triangularización
    for (int k = 0; k < result->rows && k < result->cols; k++)
    {

        // Si el pivote es muy pequeño, buscar uno mejor
        if (fabs(result->data[k][k]) < EPSILON)
        {
            int best_row = k;
            for (int i = k + 1; i < result->rows; i++)
            {
                if (fabs(result->data[i][k]) > fabs(result->data[best_row][k]))
                {
                    best_row = i;
                }
            }

            // Intercambiar filas si encontramos un pivote mejor
            if (best_row != k && fabs(result->data[best_row][k]) >= EPSILON)
            {
                matrix_swap_rows(result, k, best_row);
            }

            // Si aún es muy pequeño, saltar esta columna
            if (fabs(result->data[k][k]) < EPSILON)
            {
                continue;
            }
        }

        // Eliminación gaussiana
        for (int i = k + 1; i < result->rows; i++)
        {
            double factor = result->data[i][k] / result->data[k][k];

            for (int j = k; j < result->cols; j++)
            {
                result->data[i][j] -= factor * result->data[k][j];
            }
        }
    }

    return result;
}