#include <stdio.h>
#include <stdlib.h>

//Function to create random double integers between -1 to 1
double rand_double(double min, double max) {
    return min + ((double) rand()) / (((double) RAND_MAX / (max - min)));
}

int main() {
    int all_points, points_insidecircle = 0;
    double x, y;

    // Seeding the random number generator with the user provided seed value.
    unsigned int seed;
    printf("Enter the seed for the random number generator: ");
    scanf("%u", &seed);
    srand(seed);

    //Asking the number of iterations to be run by the user.
    printf("Enter the number of iterations to run: ");
    scanf("%d", &all_points);

// Running the random number generator with the inputted number of iterations.
    for (int i = 0; i < all_points; i++) {

        x = rand_double(-1, 1);
        y = rand_double(-1, 1);

    //Checking the number of points which would lie inside the circle.
        if (x * x + y * y <= 1) {
            points_insidecircle++;
        }
    }

//Estimating the value of pi by multiplying 4 by the points inside circle divided by all points
    double estimated_pi = 4.0 * (double)points_insidecircle / (double)all_points;

//Outputting the value of pi
    printf("The value of pi is %.2lf.\n", estimated_pi);

    return 0;
}
