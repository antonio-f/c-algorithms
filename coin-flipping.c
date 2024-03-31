/* Coin-flipping simulation

If we flip a coin N times we expect to get N/2 heads but could get anywhere 
from 0 to N heads. The program runs the experiment M times and then prints out
a histogram of the results where each asterisk represents 10 occurrences.

usage: run coin-flipping.c with arguments for N and M, for example 
    ./coin-flipping 30 1000 

*/
#include <stdio.h>
#include <stdlib.h>

// Function to simulate a coin flip and return 1 for heads, 0 for tails
int heads() {
    return rand() < RAND_MAX / 2;
}

int main(int argc, char *argv[]) {

    // Parse command-line arguments for number of coin flips (N) and number of series (M)
    int N = atoi(argv[1]), M = atoi(argv[2]);

    // Allocate memory for array to store frequency counts of heads
    int *f = malloc((N + 1) * sizeof(int));

    // Initialize frequency array to 0
    for (int j = 0; j <= N; j++)
        f[j] = 0;

    // Simulate M series of N coin flips each and update frequency array
    for (int i = 0; i < M; i++) {
        int cnt = 0; // Counter for number of heads in current series
        for (int j = 0; j <= N; j++) {
            if (heads())
                cnt++; // Increment count if heads
        }
        f[cnt]++; // Update frequency array
    }

    // Print histogram
    for (int j = 0; j <= N; j++) {
        printf("%2d ", j); // Print count of heads
        for (int i = 0; i < f[j]; i += 10)
            printf("*"); // Print asterisks representing frequency
        printf("\n");
    }

    // Free dynamically allocated memory - not needed, but good practice
    free(f);

    return 0;
}


