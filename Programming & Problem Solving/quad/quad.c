/*
 This program calculates the roots of a given quadratic equation in the form ax^2 + bx +c, it evaluates whether real
 roots of the quadratic equation exists or the equation has no real solution.
*/
#include <stdio.h>
#include <math.h>

// Function to calculate the roots of the quadratic equation
int calculateRoots(double a, double b, double c, double *root1, double *root2) {
    double discriminant = b * b - 4 * a * c;
/* 'a' is the coefficient of x^2, 'b' is the coefficient of x, 'c' is the constant */
    if (discriminant > 0) { //If the discriminant is > 0, then two roots of the equation exists.
        *root1 = (-b + sqrt(discriminant)) / (2 * a);
        *root2 = (-b - sqrt(discriminant)) / (2 * a);
        return 2; //Returns the two roots of the equation//
    } else if (discriminant == 0) {  //If the discriminant is = 0, then only one real solution exists
        *root1 = -b / (2 * a);
        return 1; // This indicates that there is only one root for the problem.
    } else {
        return 0; // This shows that there are no real roots of the problem.
    }
}

int main() {
    double a, b, c;
    double Real_Root1, Real_Root2;
    int num_Roots;
//Take input of the coefficients of the quadratic equation, and store the values in variables
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    //Recalling the function, and inputting the values of the equation//
    num_Roots = calculateRoots(a, b, c, &Real_Root1, &Real_Root2);

    //Outputting the results as per the number of real solutions//
    if (num_Roots == 2) {
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", Real_Root1);
        printf("Solution 2: %.2lf", Real_Root2);
    } else if (num_Roots == 1) {
        printf("There is one real solution: %.2lf\n", Real_Root1);
    } else {
        printf("There are no real solutions\n");
    }

    return 0;
}
//END
