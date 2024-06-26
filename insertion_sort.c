// Insertion Sort

#include <stdio.h>

void insertion_sort(int *arr, int n)
    {
        for(int i = 1; i < n; i++)
        {
            int key = arr[i];
            int j = i -1;
            while(j >= 0 && arr[j] > key)
            {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }

int main()
{
    int arr[] = {5, 8, 2, 9, 7, 3, 4, 1, 5, 1};
    insertion_sort(arr, 10);
    // printing the sorted array
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
}

/*
  USAGE: 
  gcc insertion_sort.c -o insertion_sort
  ./insertion_sort
*/
