/* hash.c v0
 * A Hash Table that stores a string and then prints it all out.
 * a. Adam T Clarkson
 * e. atclarkson@gmail.com
 * d. 2017-10-05
 */

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Define number of buckets for hash table.
#define NUM_BUCKETS 27

// Declare Functions
unsigned int hash_word(const char* word);

int main(void)
{
    // Define Variables
    char * hashtable[NUM_BUCKETS];
    int runtime = 100;
    // Initializes all array elements to be empty
    for (int j = 0; j < NUM_BUCKETS; j++)
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
        int hash = hash_word(word);

        hashtable[hash] = word;

        // Iterate through Hashtable and print entire table
        for (int j = 0; j < NUM_BUCKETS; j++)
        {
           printf("%s\n", hashtable[j]);
        }
    }
}

// Hash Function

/*
 * Adapted by Neel Mehta from
 * http://stackoverflow.com/questions/2571683/djb2-hash-function.
 */
unsigned int hash_word(const char* word)
 {
     unsigned long hash = 5381;

     for (const char* ptr = word; *ptr != '\0'; ptr++)
     {
         hash = ((hash << 5) + hash) + tolower(*ptr);
     }

     return hash % NUM_BUCKETS;
 }