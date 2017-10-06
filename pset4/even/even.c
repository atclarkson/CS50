// Make a program that is determins if an integer is odd or even

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int test = get_int("please provide an integer: ");

    if (!(test % 2))
    {
        printf("Is even!\n");
    }
    else
    {
        printf("In not even!\n");
    }

    return 0;
}