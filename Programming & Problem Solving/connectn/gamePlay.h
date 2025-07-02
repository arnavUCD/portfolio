/**
 *
 * File: gameplay.h
 * Author: [Arnav Sharma]
 *
 * Description:
 * This header file declares functions related to gameplay logic for a board game.
 * The functions include checking for a win condition and determining if the game board is full.
 *
 * Functions:
 *   1. checkForWin - Check if the last move resulted in a winning condition for the player.
 *   2. isBoardFull - Check if the game board is completely filled, indicating a draw.

 */
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

/**
 * Check for win function which checks the function for winning vertical, horizontal or diagonally.
 */
int checkForWin(char** board, int rows, int cols, int piecesToWin, char playerPiece, int row, int col);

/**
 * Function for checking if the board is full.
 */
int isBoardFull(char** board, int rows, int cols);

#endif // GAMEPLAY_H
