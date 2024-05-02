#include <stdio.h>
#include <string.h>

#define N 10000 
// N => maximum length of the input string


/**
 * The main function that reads an input string from stdin, searches 
 * for a given pattern in the input string, and prints the starting 
 * indices of all occurrences of the pattern.
 */
int main(int argc, char *argv[]) // 
{
    int i, j;
    char a[N], *p = argv[1];

    // Read input string from stdin
    fgets(a, N, stdin); // read input string into a[]

    // Removing the newline character from fgets
    a[strlen(a) - 1] = '\0'; // remove trailing newline character

    // Loop through the input string
    for (i = 0; a[i] != '\0'; i++)
    {
        // Loop through the pattern
        for (j = 0; p[j] != '\0'; j++)
        {
            // Compare characters of the input string with the pattern
            if (a[i + j] != p[j])
                break;
        }
        // If the inner loop reaches the end of the pattern, then a
        // match has been found, so print the starting index
        if (p[j] == '\0')
            printf("%d ", i); // Print the starting index of the match
    }
    printf("\n");

    return 0;
}

// example: compile, then 
// ./string_search hello
// from terminal, type: afesfhellodjakhduehellohfkuegf
// result: 5 18