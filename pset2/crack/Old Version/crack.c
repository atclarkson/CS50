// crack.c v0
#define _XOPEN_SOURCE
#include <cs50.h>
#include <crypt.h>
#include <stdio.h>
#include <string.h>
//#include <time.h>
#include <unistd.h>

int main(int argc, string argv[])
{
    // clock_t begin = clock();
    // Check that user only sent one command line input.  Error if none or more
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    string master = argv[1];
    // Get Salt
    char salt[3];
    strncpy(salt, argv[1], 2);
    salt[2] = '\0';
    // Initialize test password and set all to \0
    char testpass[6] = { '\0', '\0', '\0', '\0', '\0', '\0' };
    // Define an array with all available password characters
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\0";
    // Series of loops to iterate through above array.
    int n = strlen(letters) + 1;
    //letters[53] = '\0';
    for (int i = 0; i < n; i++)
    {
        testpass[0] = letters[i];
        for (int j = 0; j < n; j++)
        {
            //printf("%s\n", testpass);
            testpass[1] = letters[j];
            for (int k = 0; k < n; k++)
            {
                testpass[2] = letters[k];
                for (int l = 0; l < n; l++)
                {
                    testpass[3] = letters[l];
                    for (int m = 0; m < n; m++)
                    {
                        testpass[4] = letters[m];
                        //printf("*%s*\n", testpass);
                        if (strcmp(crypt(testpass, salt), master) == 0)
                        {
                            printf("%s\n", testpass);
                            // Program Timer
                            //clock_t end = clock();
                            //double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                            //printf("%.2f\n", time_spent);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    // Error message if above loop fails to crack hash
    printf("Password could not be cracked\n");
    // Program Timer
    //clock_t end = clock();
    //double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("%.2f\n", time_spent);
    return 0;
}