// Binary Search
#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x, y) ((x) < (y)) ? -1: ((x) == (y))? 0: 1
#define SWAP(x, y, t)((t) = (x), (x) = (y), (y) = (t))
#define SIZE 100 // list size

// function for array sorting
void sort(int list[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n-1; i++){
        min = i;
        for (j = i+1; j < n; j++){
            if (list[j] < list[min]){
                min = j;
            }
        SWAP(list[i], list[min], temp);
        }
    }
}

// binary search function
int binsearch(int list[], int searchnum, int left, int right)
{
    int middle;
    while (left <= right)
    {
        middle = (left + right)/2;
        switch (COMPARE(list[middle], searchnum))
        {
            case -1: left = middle + 1;
                break;
            case 0: return middle;
            case 1: right = middle - 1;
        }
    }
    return -1;
}

// binary search function - recursive
/*
int binsearch(int list[], int searchnum, int left, int right)
{
    int middle;  
    if(left <= right) {
        middle = (left + right) / 2;
        switch (COMPARE(list[middle], searchnum)){
            case -1: return binsearch(list, searchnum, middle + 1, right);
            case 0: return middle;
            case 1: return binsearch(list, searchnum, left, middle - 1);
        }
    }
    return -1;
}
*/

int main()
{   
    int list[SIZE];
    for(int i = 0; i < SIZE; i++)
    {   /* rnd generated numbers */
        list[i] = rand() % 1000;
        printf("%d ", list[i]);
    }

    sort(list, SIZE);
    printf("\n Sorted array:\n ");
    for (int i = 0; i < SIZE; i++)
    {   /* print out sorted numbers */
        printf("%d ", list[i]);
    }
    printf("\n");
    
    int num;
    printf("\nEnter number to search: ");
    scanf("%d", &num);
    printf("\nresult: %d\n", binsearch(list, num, 0, SIZE - 1) + 1);

}

