// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

#include "dictionary.h"

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    if (search(word, hashtable[hash(word)]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool search(const char *word, node *list)
{
    // create a traversal pointer
    node *ptr = list;

    // traverse until the end of the list
    while (ptr != NULL)
    {
        // if current word field is what we are looking for, return true
        if (strcasecmp(ptr->word, *word))
        {
            return true;
        }

        // if not, set ptr to the next pointer in the list
        ptr = ptr->next;
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary for reading
    FILE *d_ptr = fopen(dictionary, "r");
    // Check that dictionary is not null,  return error if null.
    if (dictionary == NULL)
    {
        fprintf(stderr, "Unable to open %s.\n", dictionary);
        return 2;
    }
    int* counter = malloc(sizeof(int));
    // check to make sure we didn't run out of memory
    if (counter == NULL)
    {
        unload();
        return false;
    }
    *counter = 0;
    int count = 0;
    string word = NULL;
    while (fscanf(d_ptr, "%s", word) != EOF)
    {
        count++;
        int l = hash(word);

        if (hashtable[l] == NULL)
        {
            // dynamically allocate size for a new node
            node *new = malloc(sizeof(node));

            // check to make sure we didn't run out of memory
            if (new == NULL)
            {
            	unload();
            	return false;
            }

            // initialize the word field
            strcpy(new->word, word);

            // initialize the next field
            new->next = hashtable[l];

            // Hashtable[l] now points to the new list
            hashtable[l] = new;
        }
        else
        {
            //dynamically allocate space for a new node
            node *add = malloc(sizeof(node));

            //check to make sure we didn’t run out of memory
            if (add == NULL)
            {
            	unload();
            	return false;
            }

            // initialize the word field
            strcpy(add->word, word);

            // initialize the next field
            add -> next = NULL;

            add -> next = hashtable[l];
            hashtable[l] = add;
        }
    }

    // close infile
    fclose(d_ptr);
    *counter = count;
    return (*counter == 0) ? false : true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int count = *counter;
    if (count < 0)
    {
        return count;
    }

    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO

    //free(d_ptr);
    //free(counter);
    return false;
}

// Hashes word to determine appropiate location in hashtable
int hash(const char *word)
{
    if (word[0] == '\'')
    {
        return 26;
    }
    else if (isalpha(word[0]))
    {
        int a = word[0];
        if ((a >= 65) && (a >= 90))
        {
            a = a + 32;
        }
        return a - 'a';
    }
    return 0;
}
