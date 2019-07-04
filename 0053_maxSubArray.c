#include <stdio.h>
#include <string.h>

#define arrSize(arr) sizeof(arr)/sizeof(*arr)

void printArray(int arr[], int s);

int maxSubArray(int* nums, int numsSize){
    int max = nums[0];
    int tempMax = nums[0];
    int temp;

    printArray(nums, numsSize);

    for (int i=1; i<numsSize; i++) {
        if (tempMax > 0) {
            temp = nums[i] + tempMax;
            tempMax = nums[i] > temp ? nums[i] : temp;
        } else {
            tempMax = nums[i];
        }
        max = tempMax > max ? tempMax : max;
        printf("Round % 2d: % 2d, % 2d\n", i, tempMax, max);
    }
    return max;
}

int main(int argc, char const *argv[]) {
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int result = maxSubArray(arr, arrSize(arr));
    printf("Result is %d\n", result);
    return 0;
}

void printArray(int arr[], int s) {
    printf("Print array: ");
    for (int i = 0; i < s; i++) {
        printf("%d,", arr[i]);
    }
    printf("\n");
}
