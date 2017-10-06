/* hash.c v0
 * A Hash Table that stores a string and then prints it all out.
 * a. Adam T Clarkson
 * e. atclarkson@gmail.com
 * d. 2017-10-05
 */

#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main(void)
{
    // Define Variables
    char * hashtable[27];
    int runtime = 100;
    // Initializes all array elements to be empty
    for (int j = 0; j < 27; j++)
        {
            hashtable[j] = "";
        }

    // Loop program for predetermined amount of time
    for (int i = 0; i < runtime; i++)
    {
        // Get a single word from user
        char *word = get_string("Please enter a single word: ");
        if (word == NULL)
        {
            printf("error on the high seas! Gotta enter something!");
            break;
        }

        int letter = (word[0] | ('a' - 'A')) -'a';
        if (word[0] == '\'')
        {
            letter = 26;
        }
        //printf("the first letter is %c\n", letter);
        hashtable[letter] = word;
        for (int j = 0; j < 27; j++)
        {
            // for (int k = 0, n = strlen(word); k < n; k++)
            // {

            // }
            printf("%s\n", hashtable[j]);
        }
    }


}