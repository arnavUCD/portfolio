/**
 * File: board.h
 * Author: [Arnav Sharma]
 *
 * Description:
 * This file contains the definition (headers) for functions related to a 2D character array (char**) representing a game board.
 * The functions include board initialization, printing, and memory deallocation.
 */
#ifndef BOARD_H
#define BOARD_H


/**
 * Function to initialize a 2D character array representing a game board.\n
 * Allocates memory for the board and returns a pointer to the allocated memory.
 */
char** initializeBoard(int rows, int cols);

/**
 * Function to print the contents of the game board to the console.
 * @param board A pointer to a pointer of characters (char**).\n
 *              This parameter will be used to store the address of the dynamically allocated 2D character array representing the game board.
 * @param rows An integer representing the number of rows in the game board.
 * @param cols An integer representing the number of columns in the game board.
 */
void printBoard(char** board, int rows, int cols);

/**
 * Function to free the memory allocated for the game board.
 */
void freeBoard(char** board, int rows);

#endif // BOARD_H
