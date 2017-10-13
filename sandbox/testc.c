#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define _XOPEN_SOURCE
#include <unistd.h>
#include <crypt.h>

#define N 44

int main(void)
{
    // Devcalare char * variables
    string *s = NULL;
    string *b = NULL;
    string salt = "50";

    // // Dyanamically allocate memory to the heap
    // *s = malloc(N + 1);
    // // Check there is enough memory
    // if (*s == NULL)
    // {
    //     printf("Cannot allocate enough memory for string\n");
    //     return 1;
    // }
    // // Dyanamically allocate memory to the heap
    // *b = malloc(N + 1);
    // // Check there is enough memory
    // if (*b == NULL)
    // {
    //     printf("Cannot allocate enough memory for string\n");
    //     return 1;
    // }

    s = "rofl";
    s = crypt(s, salt);
    b = "test";
    b = crypt(b, salt);


    printf("%s\n%s\n",*s,*b);





    // printf("%s\n", crypt(s, salt));
    // printf("%s\n", crypt(b, salt));

}

