/* crack.c v1
 * A craking program designed to crack a hash and display the password
 * We are to assume the hashed passwords are no longer than 5 charecters in
 * length and consiting of only alpha characters.
 * a. Adam T Clarkson
 * e. atclarkson@gmail.com
 * d. 2017-09-14
 */
#define _XOPEN_SOURCE
#define LETTERS "eaorinsltmdcybhgupkfjwvzxSEARMTBNOLICDPHJqKGYURWVXZQ"
#include <cs50.h>
#include <crypt.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, string argv[])
{
    // Check that user only sent one command line input.  Error if none or more
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    // Assign argv to a string variable
    string master = argv[1];
    // Get Salt
    char salt[3];
    strncpy(salt, argv[1], 2);
    salt[2] = '\0';
    // Initialize test password and set all to \0
    char testpass[6] = { '\0', '\0', '\0', '\0', '\0', '\0' };
    // Define an array with all available password characters
    // sorted by most common frequency found in passwords
    //string letters = "eaorinsltmdcybhgupkfjwvzxSEARMTBNOLICDPHJqKGYURWVXZQ";
    // Series of loops to iterate through above array.
    int n = strlen(LETTERS);
    // Test 1 Digit Passwords
    for (int i = 0; i < n; i++)
    {
        //printf("%s\n", testpass);
        testpass[0] = LETTERS[i];
        if (strcmp(crypt(testpass, salt), master) == 0)
        {
            printf("%s\n", testpass);
            return 0;
        }
    }
    // Test 2 Digit Passwords
    for (int i = 0; i < n; i++)
    {
        //printf("%s\n", testpass);
        testpass[0] = LETTERS[i];
        for (int j = 0; j < n; j++)
        {
            //printf("%s\n", testpass);
            testpass[1] = LETTERS[j];
            if (strcmp(crypt(testpass, salt), master) == 0)
            {
                printf("%s\n", testpass);
                return 0;
            }
        }
    }
    // Test 3 Digit Passwords
    for (int i = 0; i < n; i++)
    {
        //printf("%s\n", testpass);
        testpass[0] = LETTERS[i];
        for (int j = 0; j < n; j++)
        {
            testpass[1] = LETTERS[j];
            for (int k = 0; k < n; k++)
            {
                //printf("%s\n", testpass);
                testpass[2] = LETTERS[k];
                if (strcmp(crypt(testpass, salt), master) == 0)
                {
                    printf("%s\n", testpass);
                    return 0;
                }
            }
        }
    }
    // Test 4 Digit Passwords
    for (int i = 0; i < n; i++)
    {
        //printf("%s\n", testpass);
        testpass[0] = LETTERS[i];
        for (int j = 0; j < n; j++)
        {
            testpass[1] = LETTERS[j];
            for (int k = 0; k < n; k++)
            {
                testpass[2] = LETTERS[k];
                for (int l = 0; l < n; l++)
                {
                    //printf("%s\n", testpass);
                    testpass[3] = LETTERS[l];
                    if (strcmp(crypt(testpass, salt), master) == 0)
                    {
                        printf("%s\n", testpass);
                        return 0;
                    }
                }
            }
        }
    }
    // Test 5 Digit Passwords
    for (int i = 0; i < n; i++)
    {
        testpass[0] = LETTERS[i];
        for (int j = 0; j < n; j++)
        {
            printf("%s\n", testpass);
            testpass[1] = LETTERS[j];
            for (int k = 0; k < n; k++)
            {
                testpass[2] = LETTERS[k];
                for (int l = 0; l < n; l++)
                {
                    testpass[3] = LETTERS[l];
                    for (int m = 0; m < n; m++)
                    {
                        //printf("%s\n", testpass);
                        testpass[4] = LETTERS[m];
                        if (strcmp(crypt(testpass, salt), master) == 0)
                        {
                            printf("%s\n", testpass);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    // Error message if above loop fails to crack hash
    printf("Password could not be cracked\n");
    return 0;
}