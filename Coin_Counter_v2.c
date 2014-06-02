#include <stdio.h>
#include <cs50.h>
#include <math.h>

// calculates exact change in coins that a cashier usually should give to
// the customer

// define constants

#define Q 25;
#define D 10;
#define N 5;

int main(void)
{
    // define variables to store data
    
    float amount_owed = 0;
    int cent_amount = 0;
    int quarter_count = 0;
    int dime_count = 0;
    int nickel_count = 0;
    int remains = 0;
    int coin_count = 0;
    
    // prompt user for amount owed and store it in variable "amount_owed"
    // verifying the amount owed is a positive number
    
    do
    {
        printf("O Hai!  How much is owed? ");
        amount_owed = GetFloat();
    }
    while(amount_owed < 0);
    
    // convert amount from dollars and cents to cents
    
    cent_amount = (int)round(amount_owed*100);

    // determine how many quarters comprise the change due
    
    quarter_count = cent_amount / Q;
    remains = cent_amount % Q;
    
    // determine how many dimes comprise the remaining amount
    
    dime_count = remains / D;
    remains = remains % D;
    
    // determine how many nickels comprise the remaining amount
    
    nickel_count = remains / N;
    remains = remains % N;
    
    //penny count is remaining amount, add up all coin amounts for total
    // coint count and print
    
    coin_count = quarter_count + dime_count + nickel_count + remains;
    
    printf("%d\n", coin_count);
    
    return 0;
}
