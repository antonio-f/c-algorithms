/*
The program takes two inputs from the command line arguments: the first 
argument (argv[1]) is an integer N, which represents the number of random 
points to be generated, and the second argument (argv[2]) is a floating
point number d, which represents the maximum distance between points to
be considered. The program generates N random points in the unit square 
[0, 1] x [0, 1] and keeps track of the number of pairs of points within 
the distance d using the cnt counter, which is incremented whenever a 
pair of points within the distance is found.

The program uses a 2D grid of linked lists to store the points efficiently.
This allows for quick access to points within a specific region of the 
unit square. When inserting a new point, the program checks the 3x3 
neighborhood of the cell where the point is being inserted. This is done to
find pairs of points within the specified distance d. 

The running time is O(d^2 * N^2) and when d is small it constitutes a 
significant improvement over the O(N^2) algorithm used in closest_point.c.
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct // point struct
{ 
    float x; 
    float y; 
} point;


typedef struct node *link; // link is a pointer to a node
struct node {point p; link next;}; // node definition


// calculate distance between two points 
float distance(point a, point b)
{
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}


// generate random float between 0 and 1
float randFloat() 
{ return 1.0*rand()/RAND_MAX; }


// allocates 2d array of links
link **malloc2d(int r, int c)
{ 
    int i;
    link **t = malloc(r * sizeof(link *));
    for (i = 0; i < r; i++)
        t[i] = malloc(c * sizeof(link));
    return t;
}


// function to to store the given point (x, y) in the appropriate cell 
// of the grid and keep track of the number of points that are within 
// a certain distance d from the new point.
void gridinsert(float x, float y)
{ 
    int i, j; link s;
    int X = x*G + 1; int Y = y*G + 1;
    link t = malloc(sizeof *t);
    t->p.x = x; t->p.y = y; // store the point

    // iteration is over the 3x3 neighborhood of the current cell
    for (i = X-1; i <= X+1; i++)  
        for (j = Y-1; j <= Y+1; j++)
            for (s = grid[i][j]; s != NULL; s = s->next) 
                if (distance(s->p, t->p) < d) cnt++;

    t->next = grid[X][Y]; grid[X][Y] = t; // insert the point
}


link **grid; int G; float d; int cnt = 0; // global variables


int main(int argc, char *argv[])
{ 
    int i, j; 
    int N = atoi(argv[1]); // number of points
    d = atof(argv[2]); G = 1/d; // divide the unit square into a G x G grid
    grid = malloc2d(G+2, G+2);  // allocate memory for the grid
    
    // initialize the grid to NULL
    for (i = 0; i < G+2; i++)   
        for (j = 0; j < G+2; j++)
            grid[i][j] = NULL;
    
    // generate N random points and insert them into the grid
    for (i = 0; i < N; i++) 
        gridinsert(randFloat(), randFloat());

    printf("%d edges shorter than %f\n", cnt, d);
}


/* Usage: 

cc -o closest_point_grid closest_point_grid.c -lm
./closest_point_grid <number of points> <distance>

*/