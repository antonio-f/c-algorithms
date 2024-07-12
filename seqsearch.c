// Sequential search - O(n)

#include <stdio.h>

int search(int a[], int v, int l, int r)
{
    int i;
    for (i = l; i <= r; i++)
        if (v == a[i]) return i;
    return -1;
}

int main()
{
    int list[] = {5,32,7,8,9,10,14,32};
    int v;
    int l = 0;
    int r = sizeof(list)/sizeof(int);
    printf("search item ");
    scanf("%d", &v);
    printf("%d", search(list, v, 1, r));
}
