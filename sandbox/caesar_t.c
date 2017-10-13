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

    if (s != NULL && argc == 2)
    {
        for (int i = 0; i < strlen(s); i++)
        {

            if (isalpha(s[i]))
            {
                if(isupper(s[i]))
                {
                    int alphabet = s[i] - 65;
                    int result = (alphabet + key) % 26;
                    int c = result + 65;
                    printf("%c", c);
                }

                else
                {
                    int alphabet = s[i] - 97;
                    int result = (alphabet + key) % 26;
                    int c = result + 97;
                    printf("%c", c);
                }
            }

            else
            {
                printf("%c", s[i]);
            }
        }
    }

    else
    {
        return 1;
    }

    char c = 'B';
    int x = c + 2;
    printf("\n%c", x);

    printf("\n");
    return 0;


}