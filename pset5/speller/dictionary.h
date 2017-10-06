// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// Prototypes
bool check(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);
int hash(const char *word);


// Struct Definitions

// Create a linked list Struct
typedef struct node
{
    char *word[LENGTH + 1]; // The value to store in this node
    struct node *next;      // The link to the next node in the list
}
node;

// Create hashtable and assign to null
node *hashtable[27];

bool search(const char *word, node *list);

#endif // DICTIONARY_H

