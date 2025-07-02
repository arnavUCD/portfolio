/**
 * canvas.c
 *
 * This file contains the implementation of a simple 2D game board represented by a character array.
 * It provides functions for board initialization, printing, and memory deallocation.
 * Author: [Arnav Sharma, Tanay Agrawal]
 * Date: [11/12/23]
 */
#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"


/**
 * Allocates memory for a 2D character array representing the game board.
 * Initializes the 'GameBoard' structure with the specified number of rows and columns.
 * Each cell in the board is initialized with an empty space character (' ').
 *
 * @param rows Number of rows for the game board.
 * @param cols Number of columns for the game board.
 *
 * @return A pointer to the initialized 'GameBoard' structure.
 */
GameBoard* initializeBoard(int rows, int cols) {
    // Allocate memory for the board structure
    GameBoard* board = (GameBoard*)malloc(sizeof(GameBoard));
    board->rows = rows;
    board->cols = cols;

    // Allocate memory for the board
    board->board = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; ++i) {
        board->board[i] = (char*)malloc(cols * sizeof(char));
    }

    // Initialize the board with empty spaces
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            board->board[i][j] = ' ';
        }
    }

    return board;
}

/**
 * Prints the contents of the game board to the console with row and column numbers.
 * Rows are numbered in descending order, and columns are labeled with two spaces of padding.
 * Empty cells are represented by an asterisk ('*'), and other characters are printed with padding.
 *
 * @param board Pointer to the 'GameBoard' structure to be printed.
 *
 */
void printBoard(GameBoard* board) {
    int rows = board->rows;
    int cols = board->cols;

    // Print the board with row numbers
    for (int i = rows - 1; i >= 0; --i) {
        // Print the row number with two spaces of padding
        printf("%2d ", i);
        // Print each cell in the row
        for (int j = 0; j < cols; ++j) {
            // Print an asterisk for an empty cell
            if (board->board[i][j] == ' ') {
                printf(" * ");
            } else {
                // Print the character in the cell with two spaces of padding
                printf(" %c ", board->board[i][j]);
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
 * Deallocates memory for each row in the board and the board itself.
 *
 * @param board Pointer to the 'GameBoard' structure to be freed.
 */
void freeBoard(GameBoard* board) {
    // Free memory for each row in the board
    for (int i = 0; i < board->rows; ++i) {
        free(board->board[i]);
    }
    // Free the memory for the board itself
    free(board->board);
    // Free the memory for the board structure
    // free(board);
}