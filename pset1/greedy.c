#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    /* Prompt User for the amount of change owed */
    float userchange = get_float("Change owed: ");
    //Check that number is positve
    while (userchange < 0.00)
    {
        userchange = get_float("Change owed: ");
    }
    //Cast Float to an int
    userchange *= 100;
    userchange = round(userchange);
    int change = (int)userchange;
    //Declare counter variable to keep track of how many coins are returned
    int counter = 0;
    // Quarter loop
    while (change >= 25)
    {
        change -= 25;
        counter++;
        //printf("gave back a quarter, total change is now %i, and remaining money is %i\n", counter, change);
    }
    // Dime loop
    while (change >= 10)
    {
        change -= 10;
        counter++;
        //printf("gave back a dime, total change is now %i, and remaining money is %i\n", counter, change);
    }
    // Nickle loop
    while (change >= 5)
    {
        change -= 5;
        counter++;
        //printf("gave back a nickle, total change is now %i, and remaining money is %i\n", counter, change);
    }
    // Penny loop
    while (change >= 1)
    {
        change -= 1;
        counter++;
        //printf("gave back a penny, total change is now %i, and remaining money is %i\n", counter, change);
    }
    printf("%i\n", counter); //print out total number of coins as change.
}