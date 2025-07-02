/**
 * matrix.h
 *
 * Description: Header file for matrix operations. Defines the Matrix structure
 *              and declares functions for creating, deleting matrices, reading
 *              matrices from files, and calculating determinants.
 *
 * Author: [Tanay Agrawal, Arnav Sharma]
 */
#ifndef MATRIX_H
#define MATRIX_H

// Define the matrix struct
typedef struct {
    int rows;
    int cols;
    double **data;
} Matrix;

// Function declarations
Matrix* createMatrix(int Rows, int cols);
void deleteMatrix(Matrix* mat);
Matrix* readMatrixFromFile(const char* filename);
double determinant(Matrix* mat);

#endif // MATRIX_H