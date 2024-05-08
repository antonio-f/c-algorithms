// This program reads a set of edges defining a graph and builds
// and adjacency representation of the graph using an array
// of lists, one for each vertex, where the j-th list contains
// a linked list of the nodes connected to the j-th vertex

#include <stdio.h>
#include <stdlib.h>

int V = 5; // the number of vertices in the graph

// define a pointer to a node struct as the link type
typedef struct node *link; 
// define a node struct with an integer value and a pointer to the next node
struct node {int value; link next;};

// function to create a new node with the given value and next pointer
link create_node(int value, link next)  
    {
        link x = malloc(sizeof *x);
        x->value = value; 
        x->next = next;
        return x;
    }

// function to print the adjacency lists
void print_adjacency_lists(link adj[V])
{
    printf("Adjacency Lists:\n");
    for (int i = 0; i < V; i++) {
        printf("%d: ", i);
        link curr = adj[i];
        while (curr != NULL) {
            printf("%d ", curr->value);
            curr = curr->next;
        }
        printf("\n");
    }
}

// build the adjacency lists representation of the graph
int main()
{
    int i, j; link adj[V];
    for (i = 0; i < V; i++) adj[i] = NULL;
    while (scanf("%d %d\n", &i, &j) == 2)
    {
        adj[i] = create_node(j, adj[i]);
        adj[j] = create_node(i, adj[j]);
    }
    print_adjacency_lists(adj);
}

