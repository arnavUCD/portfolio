/**
 * This program checks if two input words are anagrams.\n
 * \n
 * An anagram is a word or phrase formed by rearranging the letters of another,\n
 * such as "listen" and "silent." It compares the character frequencies in the\n
 * two words to determine if they can be rearranged to form the same word.\n
 * \n
 * The user is prompted to input two words, and the program checks if they are
 * anagrams of each other, providing the result.\n
 * \n
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 21 //1 for termination command

/**
     * Convert strings to lowercase and count character occurrences
     */
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

/**
 *
 * @param thread1 is the string of letters of the first word
 * @param thread2 is the string of letters of the second word
 * @return
 * "0" or "1"
 * "0" means the statement is false and in this case that the words are not Anagram of each other.
 * "1" means the statement is true and in this case that the words are not Anagram of each other.
 */
int areAnagrams(const char *thread1, const char *thread2) {
    // Make copies of the input strings and convert them to lowercase
    char copy1[21], copy2[21];
    strcpy(copy1, thread1);
    strcpy(copy2, thread2);
    toLowerCase(copy1);
    toLowerCase(copy2);

    /**
     * Check if the threads are of different lengths
     * Returns "0" if the they are not equal, meaning they're not Anagram of each other.
     */
    if (strlen(copy1) != strlen(copy2)) {
        return 0; // Not anagrams
    }

    /**
     * Strings to store the frequency of characters in the thread.
     * Assuming only lowercase and uppercase letters
     */
    for (int i = 0; copy1[i]; i++) {
        for (int j = i + 1; copy1[j]; j++) {
            if (copy1[i] > copy1[j]) {
                char temp = copy1[i];
                copy1[i] = copy1[j];
                copy1[j] = temp;
            }
            if (copy2[i] > copy2[j]) {
                char temp = copy2[i];
                copy2[i] = copy2[j];
                copy2[j] = temp;
            }
        }
    }

    /**
     * Compare the characters in both strings.
     * If the  both the threads are not the same then they're not Anagrams of each other.
     * If they are equal then it is an Anagram.
     */

    if (strcmp(copy1, copy2) == 0) {
        return 1; // Anagrams
    } else {
        return 0; // Not anagrams
    }
}

/**
 * @param word1 is the first word that is inputted by the user.
 * @param word2 is the second word inputted by the user.
 * @return
 */
int main() {
    char word1[MAX_LENGTH], word2[MAX_LENGTH];

    printf("Please enter the first word: ");
    scanf("%20s", word1);

    printf("Please enter the second word: ");
    scanf("%20s", word2);
    /**
     * Recalls the function 'areAnagrams' and if the function returns '0'(false) it executes the else statement.\n
     * If the function returns '1'(true) then it prints that the words given are Anagrams of each other.
     */
    if (areAnagrams(word1, word2)) {
        printf("%s is an anagram of %s\n", word1, word2);
    } else {
        printf("%s is NOT an anagram of %s\n", word1, word2);
    }

    return 0;
}

/**
 * END PROGRAM
 */
