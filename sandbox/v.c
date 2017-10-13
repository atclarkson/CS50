#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string k = argv[1];
        string s = get_string("plaintext: ");
        printf("ciphertext: ");

        for (int i = 0; i < strlen(k); i++)
        {
            if(!isalpha(argv[1][i]))
            {
                printf("Error: Invalid Input");
                return 1;
            }
        }
        for (int i = 0, j = 0; i < strlen(s); i++)
        {
            if (isalpha(s[i]))
            {
                if(isupper(s[i]))
                {
                    int key = ((k[j % strlen(k)]) - 65);
                    printf("%c", (((s[i] + key) - 65)%26) + 65);
                    j++;
                }

                else
                {
                    int key = ((k[j % strlen(k)]) - 97);
                    printf("%c", (((s[i] + key) - 97)%26) + 97);
                    j++;
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
        printf("Error: Invalid Input\n");
        return 1;
    }
    printf("\n");
    return 0;
}