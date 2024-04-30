#include <stdio.h>
#include <stdlib.h>
#define N 10

// list size is N

typedef struct node *link; // links are pointers to nodes
struct node {
    int item;  // the integer value stored in the node
    link next; // pointer to the next node in the list
};

int main() {
    struct node heada, headb; // create two linked list heads
    link t, u, x, a = &heada, b; // initialize pointers

    // loop #1
    // build a linked list with one random number per node
    t = a; // set t to the head of the unsorted list
    for (int i = 0; i < N; i++)
    {   
        t->next = malloc(sizeof *t);// allocate a new node
        t = t->next; t->next = NULL;// initialize the new node
        t->item = rand() % 1000; // assign a random value between 0 and 999
    }

    // print the unsorted linked list
    struct node *curra = a->next; // start from the second node
    while(curra != NULL) {
    printf("%d ", curra->item);
    curra = curra->next;
    }

    printf("\n\n");

    /* loop #2
    implement the insertion sort algorithm to sort the linked list
    pointed to by 'a' and store the sorted list in the linked list
    pointed to by 'b'
    */
    b = &headb; b->next = NULL; // initialize the sorted list
    for (t = a->next; t != NULL; t = u) // for each node in the unsorted list
    {   
        // insert t into the sorted list b
        // t points to the node to be inserted
        u = t->next; // store the next pointer

        // loop through the sorted list, if the next node's item is greater 
        // than t->item, stop and insert t before that node
        for (x = b; x->next != NULL; x = x->next)
            if (x->next->item > t->item) break;
        t->next = x->next; x->next = t; // insert t before x->next
    }

    printf("\n");
    // Print the sorted linked list
    struct node *currb = b->next;
    while(currb != NULL) {
    printf("%d ", currb->item);
    currb = currb->next;
    }

    printf("\n\n");

    // // Free dynamically allocated memory
    // current = a->next;
    // while(current != NULL) {
    //     struct node *temp = current;
    //     current = current->next;
    //     free(temp);
    // }

    return 0;
}
