#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define arrSize(arr) sizeof(arr)/sizeof(*arr)

void printArray(int arr[], int s);

int searchInsert(int* nums, int numsSize, int target){
    for (int i=0; i<numsSize; i++) {
        if (nums[i] >= target) return i;
    }
    return numsSize;
}

int main(int argc, char const *argv[]) {
    int arr1[] = {1, 3, 5, 6};
    int target1 = 2;

    printArray(arr1, arrSize(arr1));
    printf("Target is %d\n", target1);
    int result1 = searchInsert(arr1, arrSize(arr1), target1);

    printf("Result is %d\n", result1);

    int arr2[] = {};
    int target2 = 2;

    printArray(arr2, arrSize(arr2));
    printf("Target is %d\n", target2);
    int result2 = searchInsert(arr2, arrSize(arr2), target2);

    printf("Result is %d\n", result2);

    return 0;
}

void printArray(int arr[], int s) {
    printf("Print array: ");
    for (int i = 0; i < s; i++) {
        printf("%d,", arr[i]);
    }
    printf("\n");
}
