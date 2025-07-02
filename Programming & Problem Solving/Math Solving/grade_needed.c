#include <stdio.h>

int main() {
    char desiredGrade;
    double desiredPercent, currentPercent, finalWeight, requiredFinalPercent;

    // Input
    printf("Enter the grade you want in the class: ");
    scanf(" %c", &desiredGrade);

    printf("Enter the percent you need to get that grade: ");
    scanf("%lf", &desiredPercent);

    printf("Enter your current percent in the class: ");
    scanf("%lf", &currentPercent);

    printf("Enter the weight of the final: ");
    scanf("%lf", &finalWeight);

    requiredFinalPercent = (desiredPercent - (currentPercent * (100.0 - finalWeight) / 100.0)) / (finalWeight / 100.0);

    
     printf("You need to get at least %.2lf%% on the final to get a %c in the class.\n", requiredFinalPercent, desiredGrade);

    return 0;
}
