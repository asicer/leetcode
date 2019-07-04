#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define arrSize(arr) sizeof(arr)/sizeof(*arr)

void printArray(int arr[], int s);

int* plusOne(int* digits, int digitsSize, int* returnSize){
    int value, carry = 0;
    int* res = (int*)malloc((digitsSize+1)*sizeof(int));

    value = digits[digitsSize-1] + 1;
    res[digitsSize] = value%10;
    carry = value/10;

    for (int i=digitsSize-2; i>=0; i--) {
        value = digits[i]+carry;
        res[i+1] = value%10;
        carry = value/10;
    }
    if (carry) {
        res[0] = 1;
        *returnSize = digitsSize+1;
        return res;
    } else {
        *returnSize = digitsSize;
        return res+1;
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {9, 9, 9};
    printArray(arr, arrSize(arr));
    int returnSize;
    int* retDigits = plusOne(arr, arrSize(arr), &returnSize);
    printArray(retDigits, returnSize);
    return 0;
}

void printArray(int arr[], int s) {
    printf("Print array: ");
    for (int i = 0; i < s; i++) {
        printf("%d,", arr[i]);
    }
    printf("\n");
}
