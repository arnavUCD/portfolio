/**
 * File: board.c
 * Author: [Arnav Sharma]
 *
 * Description:
 * This file contains the implementations for functions related to a 2D character array (char**) representing a game board.
 * The functions include board initialization, printing, and memory deallocation.
 */

#include <stdio.h>
#include <stdlib.h>
#include "board.h"


/**
 * Allocates memory for a 2D character array representing the game board.
 * @param rows An integer representing the number of rows in the game board.
 * @param cols An integer representing the number of columns in the game board.
 * @return char**\n
 * A pointer to the allocated memory for the game board.\n
 * The memory is initialized with empty spaces (' ') for each cell.
 */
char** initializeBoard(int rows, int cols) {
    // Allocate memory for the board
    char** board = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; ++i) {
        board[i] = (char*)malloc(cols * sizeof(char));
    }

    // Initialize the board with empty spaces
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            board[i][j] = ' ';
        }
    }

    return board;
}

/**
 * Prints the contents of the game board to the console with row and column numbers.
 * @param board A pointer to a 2D character array representing the game board.
 * @param rows An integer representing the number of rows in the game board.
 * @param cols An integer representing the number of columns in the game board.
 */
void printBoard(char** board, int rows, int cols) {
    // Print the board with row numbers
    for (int i = rows - 1; i >= 0; --i) {
        // Print the row number with two spaces of padding
        printf("%2d ", i);
        // Print each cell in the row
        for (int j = 0; j < cols; ++j) {
            // Print an asterisk for an empty cell
            if (board[i][j] == ' ') {
                printf(" * ");
            } else {
                // Print the character in the cell with two spaces of padding
                printf(" %c ", board[i][j]);
            }
        }
        // Move to the next line after printing a row
        printf("\n");
    }

    // Print column numbers below the board
    printf("   ");
    // Print each column number with two spaces of padding
    for (int j = 0; j < cols; ++j) {
        printf("%2d ", j);
    }
    printf("\n");
}

/**
 * Frees the memory allocated for the game board.
 */
void freeBoard(char** board, int rows) {
    // Free memory for each row in the board
    for (int i = 0; i < rows; ++i) {
        free(board[i]);
    }
    // Free the memory for the board itself
    free(board);
}
