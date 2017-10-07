// Implements a dictionary's functionality

#include <stdbool.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Define Structure
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

// Define Array of Node Structures
node *hashtable[NUM_BUCKETS];

// Global Variable for Tracking word count
unsigned int word_counter = 0;
// Globale variable for tracking dictionary load state
bool loaded = false;

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

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //create copy of word
    int length = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        length++;
    }

    // unsigned int length=0;
    // while(*(word+length) ) length++;


    char word_copy[length + 1];

    // convert word to lowercase
    for (int i = 0; i < length; i++)
    {
       word_copy[i] = tolower(word[i]);
    }

    // add null terminator to end of char array
    word_copy[length] = '\0';

    // Hash the word
    int hashed = hash_word(word_copy);

    // assign pointer node to the first node of the bucket
    node* pointer = hashtable[hashed];

    // check until the end of the linked list
    while (pointer != NULL)
    {
        if (strcmp(pointer->word, word_copy) == 0)
        {
            // word is in dictionary
            return true;

        }
        else
        {
            // check next node
            pointer = pointer->next;
        }
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initializes all array elements to be NULL
    for (int i = 0; i < NUM_BUCKETS; i++)
        {
            hashtable[i] = NULL;
        }

    // Open dictionary for reading
    FILE *pFile = fopen(dictionary, "r");
    // Check that dictionary is not null,  return error if null.
    if (pFile == NULL)
    {
        fprintf(stderr, "Unable to open %s.\n", dictionary);
        return false;
    }

    // Scan through Dictionary word by word until end of file is reached
    while(true)
    {
        // Allocate memory for each new word
        node *new_node = malloc(sizeof(node));
        // Check that enough memory is available
        if (new_node == NULL)
        {
            fprintf(stderr, "Not enought memory\n");
            return false;
        }

        fscanf(pFile, "%s", new_node->word);
        new_node->next = NULL;

        if (feof(pFile))
        {
            free(new_node);
            break;
        }

        // Increase word counter
        word_counter++;

        // Hash the word
        int hashed = hash_word(new_node->word);
        node *head = hashtable[hashed];

        // If bucket is empty insert first node
        if (head == NULL)
        {
            hashtable[hashed] = new_node;
        }

        // If bucket is not empty Insert Word into hash table
        else
        {
            new_node->next = hashtable[hashed];
            hashtable[hashed] = new_node;
        }
    }
    // Close the Dictionary
    fclose(pFile);
    loaded = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (loaded)
    {
        return word_counter;
    }
    else
    {
        return 0;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < NUM_BUCKETS; i++)
    {
        node *pointer = hashtable[i];
        while (pointer != NULL)
        {
            // Destroy nodes
            node* temp = pointer;
            pointer = pointer->next;
            free(temp);
        }
    }
    loaded = false;
    return true;
}
