#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define arrSize(arr) sizeof(arr)/sizeof(*arr)

void printArray(int arr[], int s);

int removeDuplicates(int* nums, int numsSize){
    if (numsSize <= 1)
        return numsSize;

    int pos = 0;
    for (int i=0; i<numsSize; i++) {
        if (nums[i] != nums[pos]) {
            nums[++pos] = nums[i];
        }
    }
    return pos+1;
}

int main(int argc, char const *argv[]) {
    // int arr[] = {};
    // int arr[] = {1};
    // int arr[] = {1, 3, 4, 5};
    int arr[] = {1, 1, 2, 3, 3, 3, 4, 5};
    printArray(arr, arrSize(arr));
    int size = removeDuplicates(arr, arrSize(arr));
    printArray(arr, size);
    return 0;
}

void printArray(int arr[], int s) {
    printf("Print array: ");
    for (int i = 0; i < s; i++) {
        printf("%d,", arr[i]);
    }
    printf("\n");
}
