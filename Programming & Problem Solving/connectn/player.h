/**
 * File: player.h
 * Author: [Arnav Sharma]
 *
 * Description:
 * This header file declares functions related to managing player actions and information in a game.
 * The functions include obtaining a player's move and determining the current player's game piece.
 *
 * Functions:
 *   1. getPlayerMove - Prompts the player for their move in the game.
 *   2. getCurrentPlayer - Returns the game piece of the current player based on the turn number.
 */
#ifndef PLAYER_H
#define PLAYER_H

int getPlayerMove(int cols);

char getCurrentPlayer(int turn);

#endif // PLAYER_H
 