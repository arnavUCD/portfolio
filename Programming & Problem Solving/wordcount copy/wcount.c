/**
 * File: wcount.c
 * Author: [Arnav Sharma]
 *
 Program Description:
 * This C program reads a text file specified as a command-line argument and counts the number of words in the file.
 * Words are considered to be sequences of one or more consecutive non-whitespace characters.
 * The program defines functions to check if a character is a word character and to count words in the file.
 * It uses these functions along with standard C file handling to achieve the word count.
 */

#include <stdio.h>
#include <ctype.h>

/**
 * Function: is_word_character\n
 * Determines whether a given character is part of a word or not.
 * @param ch The ASCII value of the character to be checked.
 * @return
 *   1 if the character is not a whitespace character (part of a word),
 *   0 if the character is a whitespace character.
 *
 *   * Note:
 *   This function relies on the standard library function isspace from ctype.h.
 *   It considers any non-whitespace character as part of a word.
 */
int is_word_character(int ch) {
    return !isspace(ch);  // Consider any non-whitespace character as part of a word
}

/**
* Function: count_words\n
 * Counts the number of words in a given file.
 * @param file A pointer to the FILE structure representing the open file.
 * @return
 * The total number of words in the file.
 *
* Implementation Details:\n
 *   The function uses a simple algorithm to iterate through each character in the file.\n
 *   It maintains a count of words by detecting transitions between whitespace and non-whitespace characters.\n
 *   If a non-whitespace character is encountered after a whitespace character, it increments the word count.\n
 *   The result is the total number of words in the file.
 */

int count_words(FILE *file) {
    int word_count = 0;
    int in_word = 0;
    int ch;

    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch)) {
            in_word = 0;
        } else {
            if (!in_word) {
                word_count++;
                in_word = 1;
            }
        }
    }

    return word_count;
}


/**
* Function: main\n
 * The main entry point of the program, responsible for handling command-line arguments,\n
 * opening the specified file, counting words, and displaying the result.
 * @param argc The number of command-line arguments.
 * @param argv An array of strings containing the command-line arguments.
 * @return
 *  0 if the program runs successfully, 1 otherwise.
 *
 *
 *  * Command-line Usage:\n
 *   The program expects exactly one command-line argument, which should be the path to the text file.\n
 *   If the correct usage is not followed, it prints a usage message and returns an error code.\n
 *\n
 * File Handling:\n
 *   The program opens the file in read-only mode and checks for errors in opening the file.\n
 *   If there's an error, it prints an error message and exits with a non-zero status.\n
 *\n
 * Word Counting:\n
 *   It calls the count_words function to determine the number of words in the file.\n
 *\n
 * Display Result:\n
 *   Prints the number of words in the file to the console.\n
 *\n
 * Cleanup:\n
 *   Closes the file before exiting the program.\n
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    int word_count = count_words(file);
    printf("There are %d word(s).\n", word_count);

    fclose(file);
    return 0;
}

/**
* END PROGRAM
*/