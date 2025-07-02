/*
 * matrix.c
 *
 * Description: This C file provides functions for creating, deleting, reading from file,
 *              and finding the determinant of matrices. The matrix structure is defined
 *              in the "matrix.h" header file.
 *
 * Author: [Tanay Agrawal, Arnav Sharma]
 */
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Allocates memory for a new Matrix structure and its data array with the specified
 * number of rows and columns. Each element in the data array is initialized to 0.
 *
 * @param rows Number of rows in the matrix.
 * @param cols Number of columns in the matrix.
 *
 * @return
 * A pointer to the newly created Matrix structure. If memory allocation fails,
 * the function prints an error message and returns NULL.
 */
Matrix* createMatrix(int rows, int cols) {
    // Allocate memory for the Matrix structure
    Matrix* mat = (Matrix*)malloc(sizeof(Matrix));
    // Check if memory allocation was successful
    if (mat == NULL) {
        printf("Error reading matrix from file\n");
        return 0;
    }

    // Set the number of rows and columns
    mat->rows = rows;
    mat->cols = cols;

    // Allocate memory for the data array (2D array)
    mat->data = (double**)malloc(rows * sizeof(double*));
    // Check if memory allocation was successful for the data array
    if (mat->data == NULL) {
        printf("Error reading matrix from file\n");
        return 0;
    }
    // Allocate memory for each row in the data array
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (double*)malloc(cols * sizeof(double));
        if (mat->data[i] == NULL) {
            printf("Error reading matrix from file\n");
            return 0;
        }
    }

    return mat;
}

/**
 * Frees the memory allocated for a Matrix structure, including its data array.
 *
 * @param mat Pointer to the Matrix structure to be deleted.
 *
 * Note:
 *   This function assumes that the Matrix structure was created using the
 *   createMatrix function. It deallocates memory for each row in the data array
 *   and then frees the memory for the data array itself and the Matrix structure.
 */
void deleteMatrix(Matrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}

/**
 *Reads a matrix from a file with the specified filename. The file is expected to
 * contain the number of rows and columns as the first line, followed by the matrix
 * elements. The function dynamically allocates memory for the matrix using the
 * createMatrix function and populates it with the values from the file.
 *
 * @param filename The name of the file to read the matrix from.
 *
 * @return
 * A pointer to the Matrix structure containing the matrix read from the file.
 *   If an error occurs (e.g., unable to open the file or memory allocation failure),
 *   the function prints an error message and returns NULL.
 */
Matrix* readMatrixFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    // Check if the file was successfully opened
    if (file == NULL) {
        printf("Error opening from file\n");
        return 0;
    }
    // Read the number of rows and columns from the file
    int rows, cols;
    fscanf(file, "%d %d", &rows, &cols);

    // Create a matrix with the specified number of rows and columns
    Matrix* mat = createMatrix(rows, cols);

    // Read matrix elements from the file and populate the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(file, "%lf", &mat->data[i][j]);
        }
    }

    fclose(file);
    return mat;
}

/**
 *Calculates the determinant of a square matrix recursively using the Laplace expansion.
 * If the matrix is not square, an error message is printed, and 0 is returned.
 *
 * @param mat Pointer to the Matrix structure for which the determinant is calculated.
 *
 * @return
 * The determinant of the input matrix. If an error occurs (non-square matrix),
 *   the function prints an error message and returns 0.
 */
double determinant(Matrix* mat) {
    if (mat->rows != mat->cols) {
        printf("Error: Matrix is not sqaure\n");
        return 0;
    }

    // Base case: If the matrix is 2x2, calculate the determinant directly
    if (mat->rows == 2) {
        return mat->data[0][0] * mat->data[1][1] - mat->data[0][1] * mat->data[1][0];
    } else {
        double det = 0;
        // Recursive calculation for larger matrices using Laplace expansion
        for (int i = 0; i < mat->rows; i++) {
            Matrix* submatrix = createMatrix(mat->rows - 1, mat->cols - 1);
            for (int j = 1; j < mat->rows; j++) {
                int col = 0;
                for (int k = 0; k < mat->cols; k++) {
                    if (k != i) {
                        submatrix->data[j - 1][col] = mat->data[j][k];
                        col++;
                    }
                }
            }
            // Update the determinant using the Laplace expansion
            det += (i % 2 == 0 ? 1 : -1) * mat->data[0][i] * determinant(submatrix);
            // Free memory allocated for the submatrix
            deleteMatrix(submatrix);
        }
        return det;
    }
}