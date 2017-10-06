// Cipher key program, takes a compand line input as the key and
// converts a plain text input from user to ciphertext via shifting
// letters by key value.
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, string argv[])
{
    // Check that user only sent one command line input.  Error if none or more
    if (argc != 2)
    {
        printf("Error: None or more than one command-line argument entered\n");
        return 1;
    }
    // Assign the cipher key value to an int variable
    int k = atoi(argv[1]);
    //printf("%i\n", k);
    string p = get_string("plaintext: ");
    printf("ciphertext: ");
    // Loop to run through Char array aka sting of plain text
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        // Check if characters is an aalphbet char and process if yes. move on and leave alone if not.
        if (isalpha(p[i]))
        {
            int offset;
            //  Determine case of char and either offest by 65 for uppr or 97 for lower.
            if (isupper(p[i]))
            {
                offset = 65;
            }
            else
            {
                offset = 97;
            }
            // Formula to run offset
            int letter = ((p[i] - offset) + k) % 26;
            int c = letter + offset;
            printf("%c", c);
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
}