#ifndef COMMANDS_H
#define COMMANDS_H
#include "canvas.h"

void drawLine(GameBoard* board, int start_row, int start_col, int end_row, int end_col);
void _delete(GameBoard* board);
void resize(GameBoard* board);
void add(GameBoard* board);
void erase(GameBoard* board);
void print_help();
void save(GameBoard *gameBoard, const char *filename);
void load(GameBoard *gameBoard, const char *filename);
// void load(GameBoard* board);

#endif // COMMANDS_H
