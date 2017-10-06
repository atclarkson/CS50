#include <stdio.h>

// Define a linked list Node
typedef struct node
{
    int val;
    struct node *next;
}
node_t;

int main(void)
{
    // Create a local variable which points to the first item of the list (called head).
    node_t * head = NULL;
    head = malloc(sizeof(node_t));
    //  Check that there is enough memory
    if (head == NULL)
    {
        return 1;
    }

    head->word = word;
    head->next = NULL;
}