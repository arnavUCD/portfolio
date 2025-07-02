/**
 * File: gameplay.c
 * Author: [Arnav Sharma]
 *
 * Description:
 * This file declares all the functions related to gameplay logic for a board game and declared in gameplay.h
 */

#include "board.h"
#include "gamePlay.h"

/**
 * Checks for a win condition horizontally on the game board.
 * @param board A pointer to a 2D character array representing the game board.
 * @param rows An integer representing the number of rows in the game board.
 * @param cols An integer representing the number of columns in the game board.
 * @param piecesToWin An integer representing the number of consecutive pieces required for a win.
 * @param playerPiece A character representing the player's game piece.
 * @param row The row index of the last move.
 * @param col The column index of the last move.
 * @return
 * int 1 if a win is detected horizontally, 0 otherwise.
 */
int checkForWin(char** board, int rows, int cols, int piecesToWin, char playerPiece, int row, int col) {

    /**
     * Check for a horizontal win
     */
    int count = 0;
    for (int j = 0; j < cols; ++j) {
        if (board[row][j] == playerPiece) {
            count++;
            if (count == piecesToWin) return 1; // Win
        } else {
            count = 0; // Reset count if consecutive pieces are not found
        }
    }

    /**
     * Check for a vertical win
     */
    count = 0;
    for (int i = 0; i < rows; ++i) {
        if (board[i][col] == playerPiece) {
            count++;
            if (count == piecesToWin) return 1; // Win
        } else {
            count = 0; // Reset count if consecutive pieces are not found
        }
    }

   /**
    * Check diagonally (from bottom-left to top-right)
    */
    count = 0;
    for (int i = 0; i < rows; i++) {
        int j = col - row + i;
        if (j >= 0 && j < cols && board[i][j] == playerPiece) {
            count++;
            if (count == piecesToWin) {
                return 1; //Player has won diagonally.
            }
        } else {
            count = 0;
        }
    }

   /**
    * Check diagonally (from top-left to bottom-right)
    */
    count = 0;
    for (int i = 0; i < rows; i++) {
        int j = col + row - i;
        if (j >= 0 && j < cols && board[i][j] == playerPiece) {
            count++;
            if (count == piecesToWin) {
                return 1; // Player has won diagonally. 
            }
        } else {
            count = 0;
        }
    }
    

    return 0; // No win
}

/**
 * Checks if the game board is completely filled, indicating a tie.
 *
 * @param board - A pointer to a 2D character array representing the game board.
 * @param rows - An integer representing the number of rows in the game board.
 * @param cols - An integer representing the number of columns in the game board.
 *
 * @return int 1 if the board is full (tie), 0 otherwise.
 */
int isBoardFull(char** board, int rows, int cols) {

    // Check if the board is full (tie)
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (board[i][j] == ' ') {
                return 0; // Board is not full
            }
        }
    }
    return 1; // Board is full (tie)
}
