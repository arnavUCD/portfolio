  #include <stdio.h>


int main() {
   int imaginary1, real1, imaginary2, real2, Result1, Result2;

printf("Enter the first complex number in the form ai + b: ");
scanf("%d i + %d", &imaginary1, &real1);

printf("Enter the second complex number in the form ai + b: ");
scanf("%d i + %d", &imaginary2, &real2);

Result1 = (real1 * real2 - imaginary1 * imaginary2);
Result2 = (real1 * imaginary2 + imaginary1 * real2);

printf("(%di + %d) * (%di + %d) ", imaginary1, real1, imaginary2, real2);
printf("= %di + %d", Result2, Result1);
    return 0;
}
