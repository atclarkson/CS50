#include <stdio.h>
#include <cs50.h>

int main(void)
{
//ask for temperature in celsius
printf("Temperature in C: ");
float c = get_float();

//convert C to F
float f = (c * 9)/5 + 32;

//display result/temperature in fahrenheit
printf("Temperature in F: %.1f\n", f);
}