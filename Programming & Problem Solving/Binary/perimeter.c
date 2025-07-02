/**
   Program: 2D Shape Perimeter Calculator\n
   Author: [Arnav Sharma]\n
   Date: [25th Nov, 2023]\n
    \n
   Description:\n
   This program calculates the perimeter of a 2D shape using vertices provided in a binary file.\n
   The file must contain at least 3 vertices to form a valid shape. The vertices are represented\n
   as points in 2D space. The program dynamically allocates memory to store the vertices, reads\n
   them from the file, calculates the perimeter using the distance formula, and displays the result.\n
    \n
   Usage: ./program_name <binary_file>\n
    \n
   Input:\n
   - The program expects a binary file name as a command-line argument.\n
    \n
   Output:\n
   - The calculated perimeter of the 2D shape.\n
    \n
   Note: Ensure that the binary file contains an integer representing the number of points\n
         followed by the x and y coordinates of each point in 2D space.\n
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Struct to represent a point in 2D space
typedef struct {
    int x;// x-coordinate of the point
    int y;// y-coordinate of the point
} Point;// Definition of the Point structure for 2D coordinates

/**
   Function: distance\n
    \n
   Description:\n
   This function calculates the Euclidean distance between two points in 2D space.\n
   It uses the distance formula: distance = sqrt((x2 - x1)^2 + (y2 - y1)^2).\n
    \n
   Parameters:\n
   - a: The first point with coordinates (x1, y1).\n
   - b: The second point with coordinates (x2, y2).\n
    \n
   Returns:\n
   The Euclidean distance between points a and b.\n

*/
double distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

/**
   Function: main

   Description:
   The main function of the program calculates the perimeter of a 2D shape using vertices
   provided in a binary file. The program dynamically allocates memory to store the vertices,
   reads them from the file, calculates the perimeter using the distance formula, and displays the result.
*/

int main(int argc, char *argv[]) {
    /**
     * Check if a binary file name is provided
     */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <binary_file>\n", argv[0]);
        return 1;
    }

    /**
     *  Open the binary file for reading
     */
    FILE *file = fopen(argv[1], "r");

    /**
     * Read the number of points from the file
     */
    int numPoints;
    fread(&numPoints, sizeof(int), 1, file);

    /**
     * Check if there are at least 3 vertices
     */
    if (numPoints < 3) {
        fprintf(stderr, "Error: The file must contain at least 3 vertices.\n");
        fclose(file);
        return 1;
    }

    /**
     * Dynamically allocate memory for the array of points
     */
    Point *vertices = (Point *)malloc(numPoints * sizeof(Point));


    /**
     * Read the vertices from the file
     */
    fread(vertices, sizeof(Point), numPoints, file);

    /**
     * Close the file
     */
    fclose(file);

    /**
     * Calculate the perimeter
     */
    double perimeter = 0.0;
    for (int i = 0; i < numPoints - 1; i++) {
        /**
         * Summing up the distances between consecutive vertices
         */
        perimeter += distance(vertices[i], vertices[i + 1]);
    }
    perimeter += distance(vertices[numPoints - 1], vertices[0]); // Closing the shape

    /**
     * Print the perimeter
     */
    printf("The perimeter is %.2f\n", perimeter);

    /**
     * Free dynamically allocated memory
     */
    free(vertices);

    return 0;
}
/**
* END PROGRAM
*/