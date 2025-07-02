/**
 * main.c
 *
 * Description: This program demonstrates the use of matrix operations by reading a matrix
 *              from a file specified as a command-line argument, calculating its determinant,
 *              and printing the result. It utilizes functions declared in the "matrix.h" header file.
 *
 * Author: [Tanay Agrawal, Arnav Sharma]
 */
#include "matrix.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    // Check if the correct number of command line arguments is provided
    if (argc != 2) {
        printf("Invalid number of arguments entered\n");
        return 0;
    }

    // Read the matrix from the file
    Matrix* mat = readMatrixFromFile(argv[1]);

    // Check if the matrix is successfully read
    if (mat == NULL) {
        printf("Error reading matrix from file\n");
        return 0;
    }

    // Find and print the determinant
    double det = determinant(mat);
    printf("The determinant is %.2f.\n", det);

    // Clean up and free memory
    deleteMatrix(mat);

    return 0;
}