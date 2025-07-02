/**
 *This C code generates and displays Pascal's Triangle based on the number of levels requested by the user.\n
 * The generatePascalsTriangle function constructs the triangle by calculating the coefficients for each level of the triangle.\n
 * It takes an input parameter pascalLevel that determines the number of levels in the triangle.
 */

#include <stdio.h>

/**
 * Function to generate Pascal's Triangle up to the specified level.
 */


#define maximumLevel 28

void generatePascalsTriangle(int pascLevel) {
    int pascArray[maximumLevel][maximumLevel];

    for (int j = 0; j < pascLevel; j++) {
        for (int i = 0; i <= j; i++) {
            if (i == 0 || i == j) {
                pascArray[j][i] = 1;
                printf("1 ");
            } else {
                pascArray[j][i] = pascArray[j - 1][i - 1] + pascArray[j - 1][i];
                printf("%d ", pascArray[j][i]);
            }
        }
        printf("\n");
    }
}

/**
 * Main function to interact with the user and call the Pascal's Triangle generation function
 * @param pascalLevel is the level of the pascal level which is inputted by the user.
 */
int main() {
    int pascalLevel
    ;

    // Prompt the user to input the desired number of levels for the Pascal's Triangle.
    printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
    scanf("%d", &pascalLevel);

    /**
     * Check if the user input is within the valid range.
     */
    if (pascalLevel < 1 || pascalLevel > 28) {
        printf("Invalid input. Level should be between 1 and 28.\n");
        return 0; // Exit the program with an error code if the input is not within the valid range.

    }

    /**
     * Generate and display Pascal's Triangle with the specified number of levels.
     * Calls the function 'generatePascalsTriangle' to create the triangle.
     */
    generatePascalsTriangle(pascalLevel);

    return 0;
}

/**
* END PROGRAM
*/