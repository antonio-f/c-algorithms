#include <stdio.h>
#include <stdlib.h>

typedef struct node *link; // links are pointers to nodes
// Define a structure for a node in a linked list
struct node {
    int item;  // The integer value stored in the node
    link next; // Pointer to the next node in the list
};

// Reverse the order of the nodes in the linked list
link reverse(link x)
{
    link t, y = x, r = NULL;
    while(y != NULL)
    {
        // <--- r ---> y ---> t --->
        t = y->next; // t is the node following y
        y->next = r; // make y point to the preceding node r
        r = y;       // r becomes the new head y
        y = t;       // y becomes the next node
        // <--- _ <--- r ---> y --->
    }
    return r;
}

/* 
Testing the reverse() function by creating a simple 3 node 
linked list (a, b, c) and passing the head node a to reverse().

After reversing, it iterates through the list starting from 
node c, which is now the new head.

It compares each node's item to an expected array {3, 2, 1}.

If any item does not match the expected value for that index, it 
prints an error and exits.

This is a basic test to verify that the reverse() function 
correctly reverses the order of the nodes in the linked list.
It tests that the original tail node (c) is now the head, and the 
original head (a) is now the tail after reversing.
*/
void test_reverse() {
  link a = malloc(sizeof *a);
  a->item = 1;
  
  link b = malloc(sizeof *b);
  b->item = 2;
  a->next = b;

  link c = malloc(sizeof *c);
  c->item = 3;
  b->next = c;

  reverse(a);

  link current = c;
  int expected[] = {3, 2, 1};
  int i = 0;
  while (current != NULL) {
    if (current->item != expected[i++]) {
      printf("Failed on element %d\n", i);
      exit(1);
    }
    current = current->next;
  }
}

// Test the reverse function with an empty list
void test_reverse_empty() {
  link head = NULL;
  reverse(head);

  if (head != NULL) {
    printf("Failed to handle empty list\n");
    exit(1);
  }
}

// Test the reverse function with a single-element list
void test_reverse_single() {
  link head = malloc(sizeof *head);
  head->item = 1;
  head->next = NULL;

  reverse(head);
  
  if (head == NULL || head->item != 1 || head->next != NULL) {
    printf("Failed on single element list\n");
    exit(1);
  }
}

/*
  Runs a series of tests to verify the correct behavior of the list reversal
  functionality.
 
  The tests cover the following cases:
  - Reversing an empty list
  - Reversing a list with a single element
  - Reversing a list with multiple elements
 
  If all tests pass, a success message is printed to the console.
 */

int main()
{
   test_reverse();
    test_reverse_empty();
    test_reverse_single();
    printf("All tests passed!\n\n");
    return 0;
}

