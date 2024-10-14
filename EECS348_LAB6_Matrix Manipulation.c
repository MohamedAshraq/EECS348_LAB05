#include <stdio.h>

#define SIZE 5

// Function prototypes
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]);
void printMatrix(int matrix[SIZE][SIZE]);
void inputMatrix(int matrix[SIZE][SIZE], const char* name);

int main() {
    int m1[SIZE][SIZE], m2[SIZE][SIZE];
    int sum[SIZE][SIZE], product[SIZE][SIZE], transpose[SIZE][SIZE];

    // Input for matrices
    inputMatrix(m1, "Matrix 1");
    inputMatrix(m2, "Matrix 2");

    printf("Matrix 1:\n");
    printMatrix(m1);

    printf("Matrix 2:\n");
    printMatrix(m2);

    // Adding matrices
    addMatrices(m1, m2, sum);
    printf("Sum of matrices:\n");
    printMatrix(sum);

    // Multiplying matrices
    multiplyMatrices(m1, m2, product);
    printf("Product of matrices:\n");
    printMatrix(product);

    // Transpose of matrix 1
    transposeMatrix(m1, transpose);
    printf("Transpose of Matrix 1:\n");
    printMatrix(transpose);

    return 0;
}

// Function to add two matrices
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to input matrix elements from user
void inputMatrix(int matrix[SIZE][SIZE], const char* name) {
    printf("Enter elements of %s (row by row):\n", name);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

