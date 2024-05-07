#include <stdio.h>
#include <stdlib.h>
#define V 5

// V is the number of vertices in the graph

void print_adjacency_matrix(int adj[V][V]); // Function to print the adjacency matrix

int main()
{
    int i, j, adj[V][V];

    // initialize the adjacency matrix with all zeros
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            adj[i][j] = 0;

    // set the diagonal elements to 1   
    for (i = 0; i < V; i++)
        adj[i][i] = 1;
    
    // read pairs of vertices from standard input and set the
    // corresponding elements in the adjacency matrix to 1
    while (scanf("%d %d\n", &i, &j) == 2) 
    {
        adj[i][j] = 1;
        adj[j][i] = 1;
    }
    print_adjacency_matrix(adj);
}


void print_adjacency_matrix(int adj[V][V]) 
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

/*
EXAMPLE

cc -o adjacency_matrix adjacency_matrix.c
./adjacency_matrix


1 2 
1 3
2 3
.

Adjacency Matrix:
1 0 0 0 0 
0 1 1 1 0 
0 1 1 1 0 
0 1 1 1 0 
0 0 0 0 1

*/