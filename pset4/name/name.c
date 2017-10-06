// A program to split a string into multiple lines

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string name = get_string("What is your name: \n");

    // Check that User actually entered a string.
    if (name == NULL)
    {
        return 1;
    }

    for (int i = 0, length = strlen(name); i < length; i++)
    {
        printf("%c\n", name[i]);
    }
}