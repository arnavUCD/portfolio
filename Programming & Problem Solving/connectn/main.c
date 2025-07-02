/**
 * main.c
 * Main file for a simple board game implementation.
 * Includes necessary header files and defines the main function for the game.
 */

#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "gamePlay.h"
#include "player.h"

	int main(int argc, char* argv[]) {
    /**
     * Check for correct command-line arguments
     */
    if(argc < 4){
      printf("Not enough arguments entered\n"
              "Usage connectn.out num_rows num_columns\n"
              "number_of_pieces_in_a_row_needed_to_win\n");
      exit(0);
    } else if (argc > 4){
        printf("Too many arguments entered\n"
               "Usage connectn.out num_rows num_columns\n"
               "number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }

    /**
     * Parse command-line arguments
     */
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    int piecesToWin = atoi(argv[3]);

    /**
     * // Validate input values
     */
    if (rows <= 0 || cols <= 0 || piecesToWin <= 0) {
        printf("Invalid input values\n");
        printf("Usage: %s num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n", argv[0]);
        return 0;
    }


    /**
     * Validate input values
     */
    char** board = initializeBoard(rows, cols);
    printBoard(board, rows, cols);

    int turn = 0;

    while (1) {

        
        const int max_times_callable = 75;
        static int num_times_called = 0;
      

        char currentPlayer = getCurrentPlayer(turn);
      
  
        int col = getPlayerMove(cols);

        
        num_times_called++;
        if (num_times_called >= max_times_callable) {
                printf("Exiting due to too many moves!\n");
                freeBoard(board, rows);
                return 0; // Return 0 to indicate an error or abnormal termination
            }
        

        /**
         * Check if the column is valid
         */
        if (col < 0 || col >= cols || board[rows - 1][col] != ' ') {
            continue;
        }

        /**
         * Make the move
         */
        int row;
        for (row = 0; row < rows; ++row) {
            if (board[row][col] == ' ') {
                board[row][col] = currentPlayer;
                break;
            }
        }

        printBoard(board, rows, cols);

        if (checkForWin(board, rows, cols, piecesToWin, currentPlayer, row, col)) {
          if (currentPlayer == 'X') {
           printf("Player 1 Won!\n");
         }
         else {
          printf("Player 2 Won!\n");
         }
         break;
        }

        /**
         * Check for a tie
         */
        if (isBoardFull(board, rows, cols)) {
            printf("Tie game!\n");
            break;
        }

        turn++;

    }

    /**
     * Free the allocated memory for the board
     */
    freeBoard(board, rows);

    return 0;
}
/**
* END PROGRAM
*/