#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Ask user for a number between 1 and 23
    int height = get_int("Height: ");
    //Check user input to verify it is less than 24
    while (height > 23)
    {
        height = get_int("Height: ");
    }
    while (height < 0)
    {
        height = get_int("Height: ");
    }
    //Loop to print pyramids on screen
    //Loop to move through rows
    for (int row = 1; row <= height; row++)
    {
        // Loop to print spaces
        for (int i = 0; i < (height - row); i++)
        {
            printf(" ");
        }
        // loop to print hashes
        for (int i = 0; i < (row); i++)
        {
            printf("#");
        }
        printf("  ");  // create 2 spaces for chasim
        // loop to print other side of pyramid
        for (int i = 0; i < (row); i++)
        {
            printf("#");
        }
        printf("\n"); // new line at end of row
    }
}