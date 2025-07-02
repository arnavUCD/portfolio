#include <stdio.h>

#define BILL_100 100       /*defining the vale of all the bills*/
#define BILL_50 50
#define BILL_20 20
#define BILL_10 10
#define BILL_5 5
#define BILL_1 1

int main() {
    int amount, num_100, num_50, num_20, num_10, num_5, num_1;

    printf("Please enter the amount of money you wish to withdraw: ");
    scanf("%d", &amount);

    num_100 = amount / BILL_100;      /*will get the number of 100 bills required for inputed vale*/
    amount = amount % BILL_100;    /*will pass over the remaining amount to the next denomination bill*/
    


    num_50 = amount / BILL_50;
    amount = amount % BILL_50;
    

    num_20 = amount / BILL_20;
    amount = amount % BILL_20;
    

    num_10 = amount / BILL_10;
    amount = amount % BILL_10;
   
    num_5 = amount / BILL_5;
    amount = amount % BILL_5;


    num_1 = amount / BILL_1;

    printf ("You received %d hundred(s)\n", num_100);
    printf ("You received %d fifty(s) \n", num_50);
    printf ("You received %d twenty(s)\n", num_20);
    printf ("You received %d ten(s)\n", num_10);
    printf ("You received %d five(s)\n", num_5 );
    printf ("You received %d one(s)\n", num_1);

    
    

    return 0;
}