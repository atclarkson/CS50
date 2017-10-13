#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    string k = argv[1];
    string s = get_string("Enter plaintext: ");
    int key = atoi(k);
    int ASCII = atoi(s);
    printf("key = %i\nASCII = %i", key, ASCII);

    if (s != NULL && argc == 2)
    {
        for (int i = 0; i < strlen(s); i++)
        {

            if (isalpha(ASCII))
            {
                if(isupper(ASCII))
                {
                    int alphabet = ASCII - 95;
                    int result = alphabet + key %26;
                    printf("%i", result);
                }

                else
                {
                    int alphabet = ASCII - 65;
                    int result = alphabet + key %26;
                    printf("%i", result);
                }
            }

            else
            {
                printf("%s", s);
            }

        }
    }

    else
    {
        return 1;
    }
    printf("\n");
    return 0;
}