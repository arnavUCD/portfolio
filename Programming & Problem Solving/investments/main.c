#include <stdio.h>

int main() {
    double loan_amount, annualinterest_rate, min_monthlypayment, monthly_money, investment_returns;
    int current_Age, retirement_Age;

    // Input validation loop for loan_amount
    do {
        printf("Enter how much you owe in loan_amount:: ");
        scanf("%lf", &loan_amount);
        if (loan_amount < 0) {
            printf("Invalid input. Please enter a valid amount for loan_amount.\n");
        }
    } while (loan_amount < 0);

    // Input validation loop for loan interest rate
    do {
        printf("Enter the annual interest rate of the loan_amount: ");
        scanf("%lf", &annualinterest_rate);
        if (annualinterest_rate < 0) {
            printf("Invalid input. Please enter a valid annual interest rate.\n");
        }
    } while (annualinterest_rate < 0);

    // Input validation loop for minimum payment
    do {
        printf("Enter your minimum monthly loan payment:: ");
        scanf("%lf", &min_monthlypayment);
        if (min_monthlypayment < 0) {
            printf("Invalid input. Please enter a valid minimum payment amount.\n");
        }
    } while (min_monthlypayment < 0);

    // Input validation loop for monthly money available
    do {
        printf("Enter how much money you will be putting towards loan_amount/retirement each month ");
        scanf("%lf", &monthly_money);
        if (monthly_money < min_monthlypayment) {
            printf("Invalid input. The monthly money should be at least the minimum payment amount.\n");
        }
    } while (monthly_money < min_monthlypayment);

    // Input validation loop for current age
    do {
        printf("Enter your current age: ");
        scanf("%d", &current_Age);
        if (current_Age < 0) {
            printf("Invalid input. Please enter a valid current age.\n");
        }
    } while (current_Age < 0);

    // Input validation loop for retirement age
    do {
        printf("Enter the age you plan to retire at: ");
        scanf("%d", &retirement_Age);
        if (retirement_Age <= current_Age) {
            printf("Invalid input. Retirement age should be greater than your current age.\n");
        }
    } while (retirement_Age <= current_Age);

    // Input validation loop for investment annual returns
    do {
        printf("Enter your predicted annual rate of return: ");
        scanf("%lf", &investment_returns);
        if (investment_returns < 0) {
            printf("Invalid input. Please enter a valid annual returns on investments.\n");
        }
    } while (investment_returns < 0);

    // Calculations
    double monthlyLoanInterest = annualinterest_rate / 12;
    double savings = 0;

    for (int age = current_Age; age < retirement_Age; age++) {
        // Interest on loan_amount is applied before anything else
        loan_amount += loan_amount * monthlyLoanInterest;

        // Allocate monthly money to loan_amount and investments
        if (loan_amount > min_monthlypayment) {
            loan_amount -= min_monthlypayment;
            savings += monthly_money - min_monthlypayment;
        } else {
            savings += monthly_money;
        }

        // Interest on investments
        savings += savings * (investment_returns / 12);
    }

    printf("Total savings at retirement age: %.2f\n", savings);
    printf("Remaining loan amount at retirement age: %.2f\n", loan_amount);

    return 0;
}

