#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define arrSize(arr) sizeof(arr)/sizeof(*arr)

void printArray(int arr[], int s);

int removeElement(int* nums, int numsSize, int val){
    int result = 0;
    for (int i=0; i<numsSize; i++) {
        if (nums[i] != val) {
            nums[result++] = nums[i];
        }
    }
    return result;
}

int main(int argc, char const *argv[]) {
    int arr[] = {1, 2, 5, 4, 2, 2, 6};
    printArray(arr, arrSize(arr));
    int size = removeElement(arr, arrSize(arr), 2);
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
