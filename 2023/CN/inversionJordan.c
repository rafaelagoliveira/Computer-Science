#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Allocate a matrix of doubles
double **allocateMatrix(int size) {
    double **matrix = (double **)malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (double *)malloc(size * sizeof(double));
    }
    return matrix;
}

// Free a matrix of doubles
void freeMatrix(double **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Print a matrix of doubles
void printMatrix(double **matrix1, double **matrix2, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%.1f ", matrix1[i][j]);
        }
        printf("\t|\t");
        for (int j = 0; j < size; j++) {
            printf("%.1f ", matrix2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Swap two rows of a matrix
void swapRows(double **matrix, int row1, int row2, int size) {
    for (int i = 0; i < size; i++) {
        double temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

// Divide a row of a matrix by a scalar
void divideRow(double **matrix, int row, double divisor, int size) {
    for (int i = 0; i < size; i++) {
        matrix[row][i] /= divisor;
    }
}

// Subtract a multiple of one row from another row
void subtractRows(double **matrix, int row1, int row2, double multiplier, int size) {
    for (int i = 0; i < size; i++) {
        matrix[row1][i] -= multiplier * matrix[row2][i];
    }
}

// Calculate the inverse of a matrix using the Jordan method
double **jordanInverse(double **matrix, int size) {
    double **inverse = allocateMatrix(size); // Allocate the inverse matrix

    // Create the identity matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                inverse[i][j] = 1.0;
            } else {
                inverse[i][j] = 0.0;
            }
        }
    }

    // Apply elementary operations to obtain the reduced row-echelon form
    for (int column = 0; column < size; column++) {
        int pivotRow = column; // Pivot row

        while (matrix[pivotRow][column] == 0) { // If the pivot element is 0, swap with another row
            pivotRow++;

            if (pivotRow == size) { // If there are no more rows below, the matrix is not invertible
                printf("The matrix is not invertible.\n");
                freeMatrix(inverse, size);
                return NULL;
            }
        }

        swapRows(matrix, column, pivotRow, size); // Swap the pivot row with the current row
        swapRows(inverse, column, pivotRow, size);

        double pivotElement = matrix[column][column];

        if (pivotElement != 0.0) {                         // If the pivot element is 0, no elementary operations are required
            divideRow(matrix, column, pivotElement, size); // Divide the current row by the pivot element
            divideRow(inverse, column, pivotElement, size);

            // Subtract the current row from all other rows
            for (int row = 0; row < size; row++) {
                if (row != column) {
                    double multiplier = matrix[row][column];
                    subtractRows(matrix, row, column, multiplier, size); // Subtract the current row from the current row
                    subtractRows(inverse, row, column, multiplier, size);
                }
            }
        }

        // Show the current step
        printf("Step %d:\n", column + 1);
        printf("Matrix | Identity Matrix:\n");
        printMatrix(matrix, inverse, size);
    }

    return inverse;
}

int main() {
    int size;

    printf("Enter the size of the matrix (up to 10): ");
    scanf("%d", &size);

    double **matrix = allocateMatrix(size);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    printf("\n");

    clock_t start = clock();

    double **inverse = jordanInverse(matrix, size);

    clock_t end = clock();
    double executionTime = (double)(end - start) / CLOCKS_PER_SEC;

    if (inverse != NULL) {
        printf("Inverse Matrix:\n");
        printMatrix(inverse, matrix, size);
        freeMatrix(inverse, size);
    }

    freeMatrix(matrix, size);

    printf("Execution Time: %.6f seconds\n", executionTime);

    return 0;
}
