// Program to determine the realness of a triangle given 3 lengths of sides
// Includes Declaration
#include <cs50.h>
#include <stdio.h>

// Function Declaration
bool valid_triangle(int a, int b, int c);

int main(void)
{
    int a = get_int("a: ");
    int b = get_int("b: ");
    int c = get_int("c: ");
    
    bool isreal = valid_triangle(a, b, c);
    printf("%d", isreal);
}

bool valid_triangle(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return false;
    }
    else if (a + b < c || a + c < b || b + c < a)
    {
        return false;
    }
    else
    {
        return true;
    }
}
