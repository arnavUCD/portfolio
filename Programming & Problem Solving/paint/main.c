/**
 * main.c
 *
 * This file contains the main program for a simple painting application using a 2D canvas.
 * The user can interact with the canvas by entering various commands, such as drawing lines,
 * resizing the canvas, adding or deleting rows/columns, erasing points, saving, and loading.
 *
 * Author: [Arnav Sharma, Tanay Agrawal]
 * Date: [11/12/23]
 */

#include "canvas.h"
#include "commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int rows, cols;

    // Check the number of command line arguments
    if (argc == 1) {
        // Default to a 10x10 board if no arguments are provided
        rows = 10;
        cols = 10;
    } else if (argc == 3) {
        // Convert command line arguments to integers
        rows = atoi(argv[1]);
        cols = atoi(argv[2]);

        if (rows <= 0 || cols <= 0) {
            if (rows < 0) {
                printf("The number of rows is less than 1.\n");
                printf("Making default board of 10 X 10.\n");
                rows = 10;
                cols = 10;
            } else {
                printf("The number of columns is less than 1.\n");
                printf("Making default board of 10 X 10.\n");
                rows = 10;
                cols = 10;
            }
        }
    }
    else {
        // Incorrect number of command line arguments
        printf("Wrong number of command line arguments entered.\n");
        printf("Usage: ./paint.out [num_rows num_cols]\n");
        printf("Making default board of 10 X 10.\n");
        rows = 10;
        cols = 10;
    }

    // Initialize the board
    GameBoard *board = initializeBoard(rows, cols);

    // Print the board
    printBoard(board);


    char command = '\0';
    int start_row, start_col, end_row, end_col;
    do {
        printf("Enter your command: ");
        do {
            if (scanf(" %c", &command) != 1 || !isalpha(command)) {
                break;  // Exit the program with an error code
            }
        } while (!isalpha(command));

        if (command == 'h') {
           print_help();
        }
        else if (command == 'w') {
            // Get line coordinates from the user
            scanf("%d %d %d %d", &start_row, &start_col, &end_row, &end_col);
            drawLine(board, start_row, start_col, end_row, end_col);
            } else if (command == 'r') {
                resize(board);
            } else if (command == 'a') {
                add(board);
            } else if (command == 'd') {
                _delete(board);
            }else if (command == 'e') {
                erase(board);
            }else if (command == 's'){
                char file_name[100];
                scanf("%s",file_name);
                save(board, file_name);
            }else if (command == 'l'){
                char file_name2[100];
                scanf("%s",file_name2);
                load(board, file_name2);
            }else if (command != 'q') {
                printf("Unrecognized command. Type h for help.\n");
            }if (command != 'q') {
                printBoard(board);
            }
            fflush(stdin);
        }
        while (command != 'q');
        freeBoard(board);

        return 0;

}
