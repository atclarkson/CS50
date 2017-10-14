// Implement a function called balanced that accepts two parameters:
// an array of integers, array, and an integer, n, that represents
// the length of array. The function should return true if array is
// balanced and false otherwise. Assume that n is positive.
#include <cs50.h>
#include <stdio.h>

bool balanced (int a[], int n);

int main (void)
{
    int b[] = {30, 22, 11, -14, 66, 1};
    int length = 6;

    bool check = balanced(b,length);
    printf("%i", check);

}

bool balanced (int a[], int n)
{
    // Declare variables for the sum of left and right side and initialize to 0
    int left = 0;
    int right = 0;

    // Declare a variable for the halfway point
    int half = n / 2;

    // Add all the left side array elements together
    for (int i = 0; i < half; i++)
    {
        left += a[i];
    }

    // Add all the left side array elements together
    for (int j = n - 1; j >= half; j--)
    {
        right += a[j];
    }

    // Check if both sides are equal
    bool result = left == right ? true : false;
    return result;
}