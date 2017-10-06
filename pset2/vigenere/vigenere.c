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
    string k = argv[1];
    for (int i = 0; i < strlen(k); i++)
    {
        if (!isalpha(k[i]))
        {
            printf("Error: Please enter only alpha characters as command-line argument.\n");
            return 1;
        }
    }
    // Assign the cipher key value to an int variable
    string p = get_string("plaintext: ");
    printf("ciphertext: ");
    // Loop to run through Char array aka sting of plain text
    for (int i = 0, j = 0, n = strlen(p), m = strlen(k); i < n; i++)
    {
        if (j >= m)
        {
           j = 0;
        }
        // Check if characters is an alphbet char and process if yes. move on and leave alone if not.
        if (isalpha(p[i]))
        {
            //  Determine case of char and either offest by 65 for upper or 97 for lower.
            int poffset = isupper(p[i]) ? 65 : 97;
            int koffset = isupper(k[j]) ? 65 : 97;
            // Formula to run offset
            //int l = atoi(k[j]);
            //int o = j % m;
            int letter = (((p[i] - poffset) + (k[j] - koffset)) % 26);
            int c = letter + poffset;
            printf("%c", c);
            j++;
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
}