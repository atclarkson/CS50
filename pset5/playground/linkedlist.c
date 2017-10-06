#include<stdio.h>

// Create a linked list

    // sllnode* create(VALUE val);

    /** Steps involved:
     * Dynamically allocate spave for ta new sllnode.
     * Check to make sure we didn't run out of memory.
     * Initialize the node's val field.
     * Initialize the node's next field.
     * Return a pointer to the newly created sll node.
     * */

// Search through a linked list to find an element

    // bool find(sllnode* head, VALUE val);

    /** Steps involved:
     * Create a traversal pointer pointing to the list's head.
     * If the current node's val field is what we're looking for, report success.
     * If not, set the traversal pointer to the next pointer in the list and go back to step b.
     * If you've reached the end of the list, report failure.
     * */

    // bool exists = find(list, 6);

// Insert a new node into the linked list.

    //  sllnode* insert(sllnode* head, VALUE val);

    /** Steps involved:
     * Dynamically allocate space for a new sllnode
     * Check to make sure we didn't run out of memory.
     * Populate and insert the node at the beginning of the linked list.
     * Return a pointer to the new head of the linked list.
     * */

// Delete an entire linked list.

    // void destroy(sllnode* head);

    /** Steps involved
     * If you've reached a null pinter, stop.
     * Delete the rest of the list.
     * Free the current node.
     * */







sllnode* new = create(6);



int main(void)
{


}