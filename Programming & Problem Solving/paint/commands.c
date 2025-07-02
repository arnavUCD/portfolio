/**
 * commands.c
 *
 * This file contains the implementation of functions related to user commands for manipulating a canvas.
 * It includes functions for printing help, drawing lines, erasing points, adding rows or columns,
 * deleting rows or columns, resizing the canvas, saving, and loading the canvas from a file.
 *
 * Author: [Arnav Sharma, Tanay Agrawal]
 * Date: [11/12/23]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include "canvas.h"

/**
 * Function: print_help
 * ---------------------
 * Prints a list of available commands and their descriptions.
 */
void print_help(){

    printf("Commands:\n");
    printf("Help: h\n");
    printf("Quit: q\n");
    printf("Draw line: w row_start col_start row_end col_end\n");
    printf("Resize: r num_rows num_cols\n");
    printf("Add row or column: a [r | c] pos\n");
    printf("Delete row or column: d [r | c] pos\n");
    printf("Erase: e row col\n");
    printf("Save: s file_name\n");
    printf("Load: l file_name\n");
}

/**
 * Function: drawLine
 * -------------------
 * Draws a line on the canvas based on the given start and end points.
 * The line can be horizontal, vertical, right diagonal, or left diagonal.
 *
 * Parameters:
 *   - board: Pointer to the 'GameBoard' structure representing the canvas.
 *   - start_row, start_col: Starting point of the line.
 *   - end_row, end_col: Ending point of the line.
 */

void drawLine(GameBoard* board, int start_row, int start_col, int end_row, int end_col) {
    // Check if the line is vertical, horizontal, right diagonal, or left diagonal
    char lineChar;

    if (start_row == end_row) {
        // Horizontal line
        lineChar = '-';
    } else if (start_col == end_col) {
        // Vertical line
        lineChar = '|';
    } else if (start_row - end_row == start_col - end_col) {
        // Right diagonal line
        lineChar = '/';
    } else if (start_row - end_row == end_col - start_col) {
        // Left diagonal line
        lineChar = '\\';
    } else {
        // Invalid line, print a message and return
        printf("Improper draw command.\n");
        return;
    }

    // Draw the line on the board
    int row = start_row;
    int col = start_col;
    char existingChar = ' '; // Initialize existing character to space

    while (row != end_row || col != end_col) {
        // Get the existing character at the current position
        existingChar = board->board[row][col];

        // Check if the cell is already occupied
        if (existingChar != ' ') {
            // Intersection detected
            if (existingChar == lineChar) {
                // Overlapping line with the same character, continue drawing
                board->board[row][col] = lineChar;
            } else {
                // Different characters, draw '+'
                board->board[row][col] = '+';
            }
        } else {
            // Draw the line character
            board->board[row][col] = lineChar;
        }

        // Move to the next cell
        if (start_row == end_row) {
            // Horizontal line
            col += (start_col < end_col) ? 1 : -1;
        } else if (start_col == end_col) {
            // Vertical line
            row += (start_row < end_row) ? 1 : -1;
        } else if (start_row - end_row == start_col - end_col) {
            // Right diagonal line
            row += (start_row < end_row) ? 1 : -1;
            col += (start_col < end_col) ? 1 : -1;
        } else if (start_row - end_row == end_col - start_col) {
            // Left diagonal line
            row += (start_row < end_row) ? 1 : -1;
            col += (start_col < end_col) ? 1 : -1;
        }
    }

    // Check for last cell intersection
    if (board->board[end_row][end_col] != ' ' && board->board[end_row][end_col] != lineChar) {
        board->board[end_row][end_col] = '+';
    } else {
        board->board[end_row][end_col] = lineChar;
    }
}


/**
 * Function: erase
 * ----------------
 * Erases a point on the canvas at the specified row and column.
 *
 * Parameters:
 *   - board: Pointer to the 'GameBoard' structure representing the canvas.
 */

void erase(GameBoard* board) {
    /**
    erases a point on the current canvas
    @board: a pointer to a struct holding the canvas contents
    @modifies: board
    */
    int row, col;

    scanf("%d %d", &row, &col);

    if (row < 0 || row >= board->rows || col < 0 || col >= board->cols) {
        printf("Improper erase command.\n");
    }
    else {
        board->board[row][col] = '*';
    }
}


/**
 * Function: add
 * --------------
 * Adds either a row or column at the user-chosen index.
 *
 * Parameters:
 *   - board: Pointer to the 'GameBoard' structure representing the canvas.
 */

void add(GameBoard* board) {
    /**
    adds either a row or column at user chosen index
    @board: a pointer to a struct holding the canvas contents
    @modifies: board
    */
    char axis;
    int pos;


    scanf(" %c %d", &axis, &pos);

    if ((axis != 'r' && axis != 'c')) {
        printf("Improper add command.\n");
    }
    else if (axis == 'r') {
        if (pos < 0 || pos > board->rows) {
            printf("Improper add command.\n");
        }
        else {
            board->rows++;
            board->board = (char**)realloc(board->board, board->rows * sizeof(char*));
            board->board[(board->rows - 1)] = (char*)realloc(board->board[(board->rows - 1)], board->cols);

            for (int row = (board->rows - 1); row > pos; --row) {
                strcpy(board->board[row], board->board[row - 1]);
            }

            for (int col = 0; col < board->cols; ++col) {
                board->board[pos][col] = '*';
            }
        }
    }
    else if (axis == 'c') {
        if (pos < 0 || pos > board->cols) {
            printf("Improper add command.\n");
        }
        else {
            board->cols++;
            for (int row = 0; row < board->rows; ++row) {
                board->board[row] = realloc(board->board[row], board->cols);

                for (int col = (board->cols - 1); col > pos; --col) {
                    board->board[row][col] = board->board[row][col - 1];
                }

                board->board[row][pos] = '*';
            }
        }
    }
}


/**
 * Function: _delete
 * ------------------
 * Deletes either a row or column at the user-chosen index.
 *
 * Parameters:
 *   - board: Pointer to the 'GameBoard' structure representing the canvas.
 */

void _delete(GameBoard* board) {
    /**
    deletes either a row or column at user chosen index
    @board: a pointer to a struct holding the canvas contents
    @modifies: board
    */
    char axis;
    int pos;


    scanf(" %c %d", &axis, &pos);

    if ((axis != 'r' && axis != 'c')) {
        printf("Improper delete command.\n");
    }
    else if (axis == 'r') {
        if (pos < 0 || pos >= board->rows) {
            printf("Improper delete command.\n");
        }
        else {
            board->rows--;

            for (int row = pos; row < board->rows; ++row) {
                strcpy(board->board[row], board->board[row + 1]);
            }
            board->board = (char**)realloc(board->board, board->rows * sizeof(char*));
        }
    }
    else if (axis == 'c') {
        if (pos < 0 || pos >= board->cols) {
            printf("Improper delete command.\n");
        }
        else {
            board->cols--;
            for (int row = 0; row < board->rows; ++row) {

                for (int col = pos; col < board->cols; ++col) {
                    board->board[row][col] = board->board[row][col + 1];
                }

                board->board[row] = realloc(board->board[row], board->cols);
            }
        }
    }
}


/**
 * Function: resize
 * -----------------
 * Resizes the current canvas based on the specified number of rows and columns.
 *
 * Parameters:
 *   - board: Pointer to the 'GameBoard' structure representing the canvas.
 */

void resize(GameBoard* board) {
    /**
    resizes the current canvas
    @board: a pointer to a struct holding the canvas contents
    @modifies: board
    */
    int new_row_dim, new_col_dim;


    scanf("%d %d", &new_row_dim, &new_col_dim);

    if (new_row_dim < 1 || new_col_dim < 1) {
        printf("Improper resize command.\n");
    }
    else {
        if (new_row_dim > board->rows) {
            int row_diff = new_row_dim - board->rows;
            for (int i = 0; i < row_diff; ++i) {
                board->rows++;
                board->board = (char**)realloc(board->board, board->rows * sizeof(char*));
                board->board[(board->rows - 1)] = (char*)realloc(board->board[(board->rows - 1)], board->cols);

                for (int col = 0; col < board->cols; ++col) {
                    board->board[(board->rows - 1)][col] = '*';
                }
            }
        }
        else if (new_row_dim < board->rows) {
            int row_diff = board->rows - new_row_dim;
            for (int i = 0; i < row_diff; ++i) {
                board->rows--;
                board->board = (char**)realloc(board->board, board->rows * sizeof(char*));
            }
        }

        if (new_col_dim > board->cols) {
            int col_diff = new_col_dim - board->cols;
            for (int i = 0; i < col_diff; ++i) {
                board->cols++;
                for (int row = 0; row < board->rows; ++row) {
                    board->board[row] = realloc(board->board[row], board->cols);
                    board->board[row][(board->cols - 1)] = '*';
                }
            }
        }
        else if (new_col_dim < board->cols) {
            int col_diff = board->cols - new_col_dim;
            for (int i = 0; i < col_diff; ++i) {
                board->cols--;
                for (int row = 0; row < board->rows; ++row) {
                    board->board[row] = realloc(board->board[row], board->cols);
                }
            }
        }
    }
}

/**
 * Function: saveFile
 * -------------------
 * Saves the current board to a file with the specified filename.
 *
 * Parameters:
 *   - board: Pointer to the 'GameBoard' structure representing the board.
 *   - file_name: Name of the file to save the board.
 */

void save(GameBoard *gameBoard, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for saving\n");
        return;
    }

    for (int i = gameBoard->rows - 1; i >= 0; i--) {
        for (int j = 0; j < gameBoard->cols; j++) {
            fputc(gameBoard->board[i][j], file);
        }
        fputc('\n', file);
    }

    fclose(file);
}

/**
 * Function: loadFile
 * -------------------
 * Loads the canvas from a file with the specified filename.
 *
 * Parameters:
 *   - board Pointer to the 'GameBoard' structure representing the canvas.
 *   - filename: Name of the file from which to load the canvas.
 */

void load(GameBoard *gameBoard, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for loading\n");
        return;
    }

    int ch;
    int row = gameBoard->rows - 1, col = 0;

    while ((ch = fgetc(file)) != EOF && row >= 0) {
        if (ch == '\n') {
            row--;
            col = 0;
        } else {
            if (col < gameBoard->cols) {
                gameBoard->board[row][col++] = ch;
            }
        }
    }

    fclose(file);
}
