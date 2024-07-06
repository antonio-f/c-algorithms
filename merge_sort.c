#include <stdio.h>
#include <stdlib.h>


void merge(int A[], int p, int q, int r)
{
    int nL = q - p + 1;
    int nR = r - q;
    // Let L[0 : nL-1] and R[0 : nR-1] be new arrays
    int L[nL];
    int R[nR];
    for (int i = 0; i<=nL-1; i++) //copy A[p:q] to L[]
        L[i] = A[p+i];
    for (int j = 0; j<=nR-1; j++) //copy A[q+1:r] to R[]
        R[j] = A[q+j+1];

    int i = 0; // indexes the smallest remaining element in L
    int j = 0; // indexes the smallest remaining element in R
    int k = p; // indexes the location in A to fill

    // As long as there are elements in L and R
    // copy the smallest unmerged element back into A
    while (i < nL && j < nR)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // Having gone through one of L and R entirely, copy the
    // remainder of the other to the end of A[p:r]
    while (i < nL)
    {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < nR)
    {
        A[k] = R[j];
        j++;
        k++;
    }

}


void merge_sort(int A[], int p, int r)
{
    if (p >= r) // if zero or one element
        return;
    int q = (p + r)/2; // middle element
    merge_sort(A, p, q); // recursively sort the left half
    merge_sort(A, q+1, r); // recursively sort the right half

    // merge the two sorted halves A[p:q] and A[q+1:r] into A[p:r]
    merge(A, p, q, r);
}


int main() {
    // generate random array
    int n = rand() % 50;
    int A[n];
    printf("random array\n");
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100;
    }
    // print random array
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    // sort the array
    merge_sort(A, 0, n-1);
    // print sorted array
    printf("\nsorted\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }   
    return 0;
}


//Usage: gcc -o merge_sort merge_sort.c &&./merge_sort