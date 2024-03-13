// Fibonacci
#include <stdio.h>

int main()
{
    int i, N, first, second, third;

    printf("how many sequence elements? ");
    scanf("%d", &N);
    
    first = 1;
    second = 1;

    printf("%d\n", first);
    printf("%d\n", second);

    for(i=2; i<N; i++)
    {
        third = first + second;
        first = second;
        second = third;
        printf("%d\n", third);
    }
}