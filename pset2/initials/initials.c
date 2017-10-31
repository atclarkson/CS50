#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    // get a sting from user
    string name = get_string();

    for(int i = 0, n = strlen(name); i < n; i++)
    if((i != 0 && name[i - 1] == 32 && isalpha(name[i])) || (i == 0 && name[i] != 32))
    {
        printf("%c", (name[i] & ~('a' - 'A')));
    }
    printf("\n");
}