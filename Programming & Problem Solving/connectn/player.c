/**
 * Implementation file for player-related functions in a game.\n
 * Defines functions to obtain a player's move and determine the current player's game piece.
 */
#include <stdio.h>
#include "player.h"

/**
 * Prompts the player for their move in the game.
 * @param cols An integer representing the number of columns in the game board.
 * @return int - The column where the player wants to place their game piece.
 */
int getPlayerMove(int cols) {
    int col;
    int max_turns = 50;

    for (int turn = 1; turn <= max_turns; ++turn) {
    printf("Enter a column between 0 and %d to play in: ", cols - 1);
    if (scanf("%d", &col) == 1) {
            break;
        } else {
            while (getchar() != '\n'); 
        }
    }
    return col;
}

/**
 * Returns the game piece of the current player based on the turn number.
 * @param turn An integer representing the current turn number.
 * @return char - The game piece ('X' or 'O') associated with the current player.
 */
char getCurrentPlayer(int turn) {
    return (turn % 2 == 0) ? 'X' : 'O';
}
