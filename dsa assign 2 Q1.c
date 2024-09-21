#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix of size rows x cols
int **allocateMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free memory allocated to a matrix
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to multiply two matrices
int **multiplyMatrices(int **mat1, int rows1, int cols1, int **mat2, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Matrix multiplication not possible.\n");
        return NULL;
    }

    // Allocate memory for the result matrix
    int **result = allocateMatrix(rows1, cols2);

    // Perform matrix multiplication
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return result;
}

// Function to print a matrix
void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Input dimensions of first matrix
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    // Input dimensions of second matrix
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    // Check if matrix multiplication is possible
    if (cols1 != rows2) {
        printf("Matrix multiplication not possible.\n");
        return 0;
    }

    // Allocate memory for matrices
    int **matrix1 = allocateMatrix(rows1, cols1);
    int **matrix2 = allocateMatrix(rows2, cols2);

    // Input elements of the first matrix
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input elements of the second matrix
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Perform matrix multiplication
    int **result = multiplyMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2);

    // Print the result matrix if multiplication was successful
    if (result != NULL) {
        printf("Result of matrix multiplication:\n");
        printMatrix(result, rows1, cols2);
        // Free dynamically allocated memory
        freeMatrix(result, rows1);
    }

    // Free dynamically allocated memory
    freeMatrix(matrix1, rows1);
    freeMatrix(matrix2, rows2);

    return 0;
}