#include <stdio.h>
#include <math.h>

int main() {
    double principal, annualInterestRate, monthlyInterestRate, totalCost, monthlyPayment;
    int numberOfMonths;

    printf("Please enter the amount of money you borrowed: $");
    scanf("%lf", &principal);

    printf("Please enter the annual interest rate: ");
    scanf("%lf", &annualInterestRate);

    printf("Please enter the number of payments to be made: ");
    scanf("%d", &numberOfMonths);

    monthlyInterestRate = (annualInterestRate / 12);

    monthlyPayment = (principal * monthlyInterestRate) / (1- pow(1+monthlyInterestRate, -numberOfMonths));

    totalCost = (monthlyPayment*numberOfMonths);

    // Output
    printf("A loan of %.2lf", principal);
    printf(" with an annual interest of %.2lf paid off over %d months", annualInterestRate, numberOfMonths);
    printf(" will have monthly payments of %.2lf.\n", monthlyPayment);
    printf("In total, you will pay %.2lf,\n", totalCost);

    return 0;
}
