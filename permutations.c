// Permutations
#include <stdio.h>
#define SWAP(x, y, t)((t) = (x), (x) = (y), (y) = (t))

void perm(char *list, int i, int n);

int main()
{   
    int l = 4;
    char letters[] = {'a', 'b', 'c', 'd'};

    printf("\n");
    perm(letters, 0, l-1);
    printf("\n");
}

void perm(char *list, int i, int n)
{
    int j, temp;
    if (i == n)
    {
        for(j = 0; j <= n; j++)
            printf("%c", list[j]);
        printf("   ");
    }
    else
    {
        for(j = i; j <= n; j++)
        {
            SWAP(list[i], list[j], temp);
            perm(list, i+1, n);
            SWAP(list[i], list[j], temp);
        }
    }
}

