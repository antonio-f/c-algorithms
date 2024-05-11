/*
The program takes two inputs from the command line arguments: the first 
argument (argv[1]) is an integer N, which represents the number of random 
points to be generated, and the second argument (argv[2]) is a floating
point number d, which represents the maximum distance between points to
be considered. 
The program generates N random points in the unit square [0, 1] x [0, 1] 
and then prints the coordinates of all the points that are within the 
maximum distance d of each other.
This is not a fast algorithm, as it has a time complexity of O(N^2), where 
N is the number of points. However, it is a simple and straightforward 
implementation that should work for small to medium-sized datasets.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct 
{ 
    float x; 
    float y; 
} point;

float randFloat()
{ return 1.0*rand()/RAND_MAX; }

float distance(point a, point b)
{
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

void print_points(point a, point b)
{
    printf("(%f, %f) ~ (%f, %f)\n", a.x, a.y, b.x, b.y);
}

int main(int argc, char *argv[])
{ 
    float d = atof(argv[2]);
    int i, j, cnt = 0, N = atoi(argv[1]);
    point *a = malloc(N*(sizeof(*a)));
    for (i = 0; i < N; i++)
    { 
        a[i].x = randFloat(); 
        a[i].y = randFloat(); 
    }
    for (i = 0; i < N; i++)
        for (j = i+1; j < N; j++)
            if (distance(a[i], a[j]) < d) 
            {
                cnt++;
                print_points(a[i], a[j]);;
            }
    printf("%d edges shorter than %f\n", cnt, d);
    return 0;
}

/*
EXAMPLE

cc -o closest_point closest_point.c -lm
./closest_point 10 0.2

(0.783099, 0.798440) ~ (0.635712, 0.717297)
(0.335223, 0.768230) ~ (0.477397, 0.628871)
(0.277775, 0.553970) ~ (0.364784, 0.513401)
(0.277775, 0.553970) ~ (0.141603, 0.606969)
(0.477397, 0.628871) ~ (0.364784, 0.513401)
(0.477397, 0.628871) ~ (0.635712, 0.717297)
6 edges shorter than 0.200000

*/