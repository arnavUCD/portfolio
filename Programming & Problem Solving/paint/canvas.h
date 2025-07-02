#ifndef CANVAS_H
#define CANVAS_H

// Define the structure for the game board
typedef struct {
    int rows;
    int cols;
    char **board;
} GameBoard;

GameBoard* initializeBoard(int rows, int cols);
void printBoard(GameBoard* board);
void freeBoard(GameBoard* board);


#endif // CANVAS_H
