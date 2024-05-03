// Sorting an array of strings

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Nmax 5 
#define Mmax 100

// Nmax: maximum number of strings
// Mmax: maximum length of each string

char buf[Mmax]; // buffer to store the input strings
int M = 0; // current position in the buffer

// define the compare function for qsort
// void pointers can point to any data type, so later we will
// need to cast them to the appropriate type (char** in our case)
int compare(const void *i, const void *j) 
{
    // compare two string pointers
    // *(char **)i and *(char **)j dereference these void pointers 
    // to obtain the actual string values they are pointing to
    return strcmp(*(char **)i, *(char **)j);
}

int main()
{
    int i, N; 
    char* a[Nmax]; // array of pointers to strings
    
    // read input strings and store them in the buffer
    for (N = 0; N < Nmax; N++)
    {
        a[N] = &buf[M];
        if (scanf("%s", a[N]) == EOF) break; 
        M += strlen(a[N])+1; // update the current position in the buffer
    }

    // sort the array of string pointers using qsort
    qsort(a, N, sizeof(char*), compare);

    printf("\n");
    
    // print the sorted strings
    for (i = 0; i < N; i++) printf("%s\n", a[i]);

    return 0;
}