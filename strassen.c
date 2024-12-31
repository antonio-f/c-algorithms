/*
Strassen's algorithm is an advanced matrix multiplication technique that reduces the time 
complexity from O(n^3) to approximately O(n^2.81). It does this by breaking matrices into
smaller sub-matrices and performing fewer multiplications than traditional methods.
The key idea is to reduce the number of multiplications required from eight (in the 
classical method for two n by n matrices) to seven by cleverly combining additions and 
subtractions. This is achieved through seven specific linear combinations of the 
sub-matrices, which reduce computational complexity.

Here’s a brief outline of the algorithm:

1. Divide: Each matrix is divided into four smaller sub-matrices.
2. Compute: Perform seven specific multiplications of these sub-matrices (using linear 
    combinations).
3. Combine: Use the results of the seven multiplications to compute the final product of the 
    two matrices.
4. Recursive: For larger matrices, the process is recursively applied to smaller sub-matrices.

Despite being faster in theory, Strassen's algorithm has practical limitations. It requires 
additional memory for intermediate sub-matrices and is prone to numerical instability for 
large matrices. As a result, other algorithms, such as the classical matrix multiplication or 
more advanced methods like the Coppersmith-Winograd algorithm, are preferred for large-scale
applications, especially where precision and stability are critical.
 */

#include <stdio.h>
#include <stdlib.h>

// Function to add two matrices
void add(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract one matrix from another
void subtract(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to perform matrix multiplication using Strassen's algorithm
void strassen(int n, int A[n][n], int B[n][n], int C[n][n]) {
    if (n == 1) {
        // Base case: multiplication of 1x1 matrices
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int new_size = n / 2;  // Size of the submatrices
    int A11[new_size][new_size], A12[new_size][new_size], A21[new_size][new_size], A22[new_size][new_size];
    int B11[new_size][new_size], B12[new_size][new_size], B21[new_size][new_size], B22[new_size][new_size];
    int M1[new_size][new_size], M2[new_size][new_size], M3[new_size][new_size], M4[new_size][new_size];
    int M5[new_size][new_size], M6[new_size][new_size], M7[new_size][new_size];
    int temp1[new_size][new_size], temp2[new_size][new_size];

    // Divide matrices A and B into 4 submatrices each
    for (int i = 0; i < new_size; i++) {
        for (int j = 0; j < new_size; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + new_size];
            A21[i][j] = A[i + new_size][j];
            A22[i][j] = A[i + new_size][j + new_size];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + new_size];
            B21[i][j] = B[i + new_size][j];
            B22[i][j] = B[i + new_size][j + new_size];
        }
    }

    // Compute the 7 intermediate products
    // M1 = (A11 + A22) * (B11 + B22)
    add(new_size, A11, A22, temp1);
    add(new_size, B11, B22, temp2);
    strassen(new_size, temp1, temp2, M1);

    // M2 = (A21 + A22) * B11
    add(new_size, A21, A22, temp1);
    strassen(new_size, temp1, B11, M2);

    // M3 = A11 * (B12 - B22)
    subtract(new_size, B12, B22, temp2);
    strassen(new_size, A11, temp2, M3);

    // M4 = A22 * (B21 - B11)
    subtract(new_size, B21, B11, temp2);
    strassen(new_size, A22, temp2, M4);

    // M5 = (A11 + A12) * B22
    add(new_size, A11, A12, temp1);
    strassen(new_size, temp1, B22, M5);

    // M6 = (A21 - A11) * (B11 + B12)
    subtract(new_size, A21, A11, temp1);
    add(new_size, B11, B12, temp2);
    strassen(new_size, temp1, temp2, M6);

    // M7 = (A12 - A22) * (B21 + B22)
    subtract(new_size, A12, A22, temp1);
    add(new_size, B21, B22, temp2);
    strassen(new_size, temp1, temp2, M7);

    // Declare C11, C12, C21, C22 to store the resulting submatrices
    int C11[new_size][new_size], C12[new_size][new_size], C21[new_size][new_size], C22[new_size][new_size];

    // Combine the results to get the final matrix C
    // C11 = M1 + M4 - M5 + M7
    add(new_size, M1, M4, temp1);
    subtract(new_size, temp1, M5, temp1);
    add(new_size, temp1, M7, C11);

    // C12 = M3 + M5
    add(new_size, M3, M5, C12);

    // C21 = M2 + M4
    add(new_size, M2, M4, C21);

    // C22 = M1 - M2 + M3 + M6
    add(new_size, M1, M2, temp1);
    subtract(new_size, temp1, M3, temp1);
    add(new_size, temp1, M6, C22);

    // Reassemble the final matrix C from C11, C12, C21, and C22
    for (int i = 0; i < new_size; i++) {
        for (int j = 0; j < new_size; j++) {
            C[i][j] = C11[i][j];
            C[i][j + new_size] = C12[i][j];
            C[i + new_size][j] = C21[i][j];
            C[i + new_size][j + new_size] = C22[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Main function to test the implementation
int main() {
    int n = 4; // Size of the matrices
    int A[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int B[4][4] = {{16, 15, 14, 13}, {12, 11, 10, 9}, {8, 7, 6, 5}, {4, 3, 2, 1}};
    int C[4][4]; // Result matrix

    // Call Strassen's matrix multiplication function
    strassen(n, A, B, C);

    // Print the result
    printf("Result of Strassen's matrix multiplication:\n\n");
    printMatrix(n, C);

    return 0;
}
