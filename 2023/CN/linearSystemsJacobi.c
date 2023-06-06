#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ITERATIONS 1000

// Allocate a matrix of doubles
double **allocateMatrix(int rows, int columns) {
    double **matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double *)malloc(columns * sizeof(double));
    }
    return matrix;
}

// Free a matrix of doubles
void freeMatrix(double **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Print a double vector
void printVector(double *vector, int size) {
    for (int i = 0; i < size; i++) {
        printf("%.7f ", vector[i]);
    }
    printf("\n");
}

// Calculate the error between two solutions
double calculateError(double *previousSolution, double *currentSolution, int size) {
    double error = 0.0;
    for (int i = 0; i < size; i++) {
        double difference = currentSolution[i] - previousSolution[i]; // Difference between the solutions
        error += difference * difference; // Sum of squared differences
    }
    return sqrt(error);
}

// Solve a linear system using the Jacobi method
void jacobiMethod(double **coefficients, double *constants, int size, double precision, double *initialSolution) {
    double *solution = (double *)malloc(size * sizeof(double));
    double *previousSolution = (double *)malloc(size * sizeof(double));

    // Initialize the solutions
    for (int i = 0; i < size; i++) {
        solution[i] = initialSolution[i];
        previousSolution[i] = 0.0;
    }

    int iterations = 0;
    double error = precision + 1.0;

    clock_t start = clock();

    // Iterate until the error is smaller than the precision or the maximum number of iterations is reached
    while (error > precision && iterations < MAX_ITERATIONS) {
        for (int i = 0; i < size; i++) {
            double sum = constants[i];
            for (int j = 0; j < size; j++) {
                if (i != j) {
                    sum -= coefficients[i][j] * previousSolution[j];
                }
            }
            solution[i] = sum / coefficients[i][i]; // Calculate the solution
        }

        error = calculateError(previousSolution, solution, size); // Calculate the error
        iterations++;

        for (int i = 0; i < size; i++) { // Update the previous solution
            previousSolution[i] = solution[i];
        }

        // Show the current step
        printf("Step %d:\n", iterations);
        printf("Solution:\n");
        printVector(solution, size);
        printf("Error: %.7f\n", error);
        printf("\n");
    }

    clock_t end = clock();
    double executionTime = (double)(end - start) / CLOCKS_PER_SEC;

    if (iterations == MAX_ITERATIONS) {
        printf("The Jacobi method reached the maximum number of iterations.\n");
    } else {
        printf("Convergence achieved in %d iterations.\n", iterations);
    }

    printf("\nFinal solution:\n");
    printVector(solution, size);

    printf("Execution time: %.6f seconds\n", executionTime);

    free(solution);
    free(previousSolution);
}

int main() {
    int size;

    printf("\nEnter the order of the system (up to 10): ");
    scanf("%d", &size);

    double **coefficients = allocateMatrix(size, size);
    double *constants = (double *)malloc(size * sizeof(double));
    double *initialSolution = (double *)malloc(size * sizeof(double));

    printf("\nEnter the coefficients of the unknowns:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%lf", &coefficients[i][j]);
        }
    }

    printf("\nEnter the constants of the system:\n");
    for (int i = 0; i < size; i++) {
        scanf("%lf", &constants[i]);
    }

    double precision;

    printf("\nEnter the desired precision: ");
    scanf("%lf", &precision);

    printf("\nEnter the initial solution:\n");
    for (int i = 0; i < size; i++) {
        scanf("%lf", &initialSolution[i]);
    }

    printf("\n");

    jacobiMethod(coefficients, constants, size, precision, initialSolution);

    freeMatrix(coefficients, size);
    free(constants);
    free(initialSolution);

    return 0;
}
