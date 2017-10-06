#define _XOPEN_SOURCE 
#include <string.h>
#include <cs50.h>
#include <crypt.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, string argv[])
{
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
    
    string testpass ='\0';
    for (string testpass ="A"; testpass <= "zzzz"; testpass++)
    {
        if(strcmp(crypt(testpass, salt), master) == 0)
        {
            printf("%s\n", testpass);
            return 0;
        }
    }
}