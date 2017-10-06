/* hash.c v0
 * A Hash Table that stores a string and then prints it all out.
 * a. Adam T Clarkson
 * e. atclarkson@gmail.com
 * d. 2017-10-05
 */

#include<stdio.h>
#include<cs50.h>
#include<string.h>

int hash_function(char *word);

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
        // Check that user entered a string
        if (word == NULL)
        {
            printf("error on the high seas! Gotta enter something!");
            break;
        }
        int hash = hash_function(word);

        hashtable[hash] = word;

        // Iterate through Hashtable and print entire table
        for (int j = 0; j < 27; j++)
        {
           printf("%s\n", hashtable[j]);
        }
    }
}

// Hash Function
int hash_function(char *word)
{
    int hash = (word[0] | ('a' - 'A')) -'a';
    if (word[0] == '\'')
    {
        hash = 26;
    }
    return hash;
}