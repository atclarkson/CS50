#include <cs50.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

typedef wchar_t emoji;

emoji get_emoji(string prompt);

int main(void)
{
    // Set locale according to environment variables
    setlocale(LC_ALL, "");

    // Prompt user for code point
    emoji c = get_emoji("Code point: ");

    // Print character
    printf("%lc\n", c);
}

emoji get_emoji(string prompt)
{
    // Get a string from user
    // while (true)
    // {
        string s = get_string("%s", prompt);
        if ((s[0] == 'U' || s[0] == 'u') && s[1] == '+')
        {
            s[0] = '0';
            emoji out = 0;
            //mbstowcs(*out, *s, size_t size);
            emoji bit = mbstowcs(&out, s, 4);
            return bit;
        }
    // }
    return false;
}