#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Get number of minutes from user then print to screen the number of bottles their shower would be equivelent to
    printf("minutes: ");
    int minutes = GetInt();
    printf("bottles: %i\n", minutes*12);
 
    return 0;    
}