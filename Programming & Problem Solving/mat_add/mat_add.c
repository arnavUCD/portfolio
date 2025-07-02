/**
 * This program is designed to perform the addition of two matrices with max order(Rows x Column) of the matrix being 100x100.\n
 * \n
 * It allows the user to input the number of rows and columns for the matrices, followed by the matrix elements.
 * The program then adds the corresponding elements of the two matrices and displays the result.
 */

#include <stdio.h>

/**
 * @param maxRows defines the maximum number of rows to be 100.
 *@param maxColumns defines the maximum number of columns to be 100.
 */

#define maxRows 100
#define maxColumns 100


/**
 * The function addMatrices performs the major calculations of the program.\n
 * It takes all the elements of the matrix and assign them into rows and columns accordingly.\n
 * \n
 * The function uses two nested loops to go through each element (or cell) of the matrices.
   The outer loop goes through the rows, and the inner loop goes through the columns.\n
   \n
 * Once the loops have gone through all the cells in both matrices, you have your final result in the resultMatrix. It contains the sum of matrixA and matrixB.\n
 * For each cell in the matrices, it adds the values from the same cell in matrixA and matrixB,
   and stores the result in a corresponding cell in the resultMatrix.
 * @param rows- is the number of rows in the specified matrix.
 * @param columns- is the number of columns in the specified matrix
 * @param matrixA- is the first matrix the user will input
 * @param matrixB- is the second matrix user will input
 * @param resultMatrix - is the resultant matrix obtained by the addition of the respective elements of each matrix.
 */

void addMatrices(int rows, int columns, int matrixA[maxRows][maxColumns], int matrixB[maxRows][maxColumns], int resultMatrix[maxRows][maxColumns]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            resultMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}


/**
 * The main function takes the inputs from the user about the number of rows and columns.\n
 * \n
 * It recalls the additionMatrices function to get the result of the addition.\n
 * \n
 * The two nested for loops are used to iterate through each element (cell) of the resultMatrix, just like in the previous function.
 * The outer loop iterates through the rows, and the inner loop iterates through the columns.\n
 * \n
 * printf("%d ", resultMatrix[i][j]); - Inside the nested loops, this line prints the value at the current cell of the resultMatrix.
 * It prints the value as an integer followed by a space.\n
 * \n
 * printf("n"); - After printing all the values in a row (which corresponds to a row in the resultMatrix),
 * this line adds a newline character (n) to move to the next line.\n
 */

int main() {
    int rows, columns;
    int matrixA[maxRows][maxColumns], matrixB[maxRows][maxColumns], resultMatrix[maxRows][maxColumns];

    printf("Please enter the number of rows: ");
    scanf("%d", &rows);

    printf("Please enter the number of columns: ");
    scanf("%d", &columns);

    printf("Enter Matrix A\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter Matrix B\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    addMatrices(rows, columns, matrixA, matrixB, resultMatrix);

    printf("A + B =\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }
    printf("The program has worked successfully.\n");
    return 0;
}

/*
 * END PROGRAM
 */
