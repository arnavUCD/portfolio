/**
 * Program: Recursive Function to Calculate foo(n)
 * Author: [Arnav Sharma, Tanay Agrawal]
 * Description: This program defines a recursive function foo(n) that calculates the value
 *              based on the recurrence relation. The main function takes user input for
 *              the value of 'n', calls the foo function, and displays the result.
 *              The recursive function _fooHelper is used to implement the recursive logic
 *              with multiple arguments.
 */
#include <stdio.h>

// A recursive function to calculate foo(n)
int _fooHelper(int n, int n4, int n3, int n2, int n1) {
    // Base cases
    if (n == 0) {
        return n4;// foo(0) is n4
    }if (n == 1) {
        return n3;// foo(1) is n3
    }if (n == 2) {
        return n2;// foo(2) is n2
    }if (n == 3) {
        return n1;// foo(1) is n1
    }
    // Recursive call with multiple arguments
    return _fooHelper(n - 1, n3, n2, n1, n1 + n2 + n3 - n4 + 1);
}
// Function to calculate foo(n) using _fooHelper
int foo(int n) {
    return _fooHelper(n, 3, 6, 2, 7);
}
// Main function to take user input, call foo, and display the result
int main() {
    int N, answer;
    printf("Enter a value for n: ");
    scanf("%d", &N);
    answer = foo(N);
    printf("Foo(%d) = %d\n", N, answer);
    return 0;
}
/**
* END PROGRAM
*/