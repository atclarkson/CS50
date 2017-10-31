#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask user for minutes.
    int minutes = get_int("Minutes: ");
    // Print out total number of bottles
    printf("Bottles: %.0f\n", ((minutes * 1.5 * 128) / 16));
}