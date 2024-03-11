// Bubble Sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
    int ctr, inner, outer, didSwap, temp;
    int nums[10];
    time_t t;
    
    srand(time(&t));
    
    // Fill the array with random numbers
    for (ctr = 0; ctr < 10; ctr++)
    {
        nums[ctr] = (rand() % 99) + 1;
    }
    
    // List the original array
    puts("\nList before the sort:");
    for (ctr = 0; ctr < 10; ctr++)
    {
        printf("%d  ", nums[ctr]);
    }

    // Sort the array
    for (outer = 0; outer < 9; outer++)
    {
        didSwap = 0; // Becomes 1 (true) if list is not yet ordered
        for (inner = outer; inner < 10; inner++) 
        {
            if (nums[inner] < nums[outer])
            {
                temp = nums[inner];
                nums[inner] = nums[outer];
                nums[outer] = temp;
                didSwap = 1;
            }
        }
    
        if (didSwap == 0) 
        {
            break;
        }
      }
    
    // List the array after sorting
    puts("\nList after the sort:");
    for (ctr = 0; ctr < 10; ctr++)
    {
        printf("%d  ", nums[ctr]);
    }
    printf("\n");
    
    return(0);
}
