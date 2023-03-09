#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int largestPerimeter(int* nums, int numsSize){
    
    // find largest sum of sides
    //sort list ascending
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int threeNums[3] = {nums[numsSize-1], nums[numsSize-2], nums[numsSize-3]};
    //if threenums contains 0 return 0
    // else return sum of three nums
    int perimeter = 0;
    for (int i = 0; i < 3; i++) {
        if (threeNums[i] == 0) return 0;
        perimeter += threeNums[i];
    }
    return perimeter;
    
}

int main() {
    int input[3] = {1, 2, 3};
    printf("output: %d\n\n", largestPerimeter(input, 3));
}