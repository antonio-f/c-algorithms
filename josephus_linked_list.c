// Josephus problem using linked list
// https://en.wikipedia.org/wiki/Josephus_problem

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in a circular linked list
typedef struct node *link;
struct node {
    int item;  // The integer value stored in the node
    link next; // Pointer to the next node in the list
};

int main(int arg, char *argv[])
{
    int i, N = atoi(argv[1]), M = atoi(argv[2]); // Read N and M from command line arguments
    link t = malloc(sizeof *t), x = t;           // Create two pointers for linked list manipulation
    t->item = 1; t->next = t;                    // Initialize the first node with item 1 and point it to itself

    // Create nodes for the circular linked list representing people in the circle
    for (i = 2; i <= N; i++) {
        // Create a new node, connect it to the preceding node, and "move" x to the new node
        x = (x->next = malloc(sizeof *x));
        x->item = i; x->next = t; // Set the item value and make the new node point back to the first node
    }

    // Eliminate people from the circle until only one person remains
    while (x != x->next) {  // until only one person left in the circle (x is pointing to itself)
        for (i = 1; i < M; i++) // Move to the Mth person in the circle
            x = x->next;
        // After skipping M - 1 people, the following line removes the Mth person from the circle
        // by adjusting the next pointer of the current node (x).  The next pointer of x point to 
        // the node following the Mth person, effectively bypassing them.
        x->next = x->next->next; 
        N--;                     // Decrement the total number of people in the circle
    }

    // Print the item (position) of the last remaining person
    printf("%d\n", x->item);
}