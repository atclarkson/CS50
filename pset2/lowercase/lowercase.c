// Alternates letters in a string to be upper then lower case.
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
    string s = get_string("Input:  ");
    printf("Output: ");
    
    for(int i = 0, j = 0, n = strlen(s); i < n; i++, j++)
    {
        if (isalpha(s[i]) && j % 2 == 0)
        {
            //char result = islower(s[i]) ? s[i] - 32 : s[i];
            char result = s[i] & ~('a' - 'A');
            printf("%c", result);
        }
        else if (isalpha(s[i]))
        {
            //char result = isupper(s[i]) ? s[i] + 32 : s[i];
            char result = s[i] | ('a' - 'A');
            printf("%c", result);
        }
        else
        {
            printf("%c", s[i]);
            j--;
        }
    }
    printf("\n");
    return 0;
}
