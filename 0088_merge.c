#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define arrSize(arr) sizeof(arr)/sizeof(*arr)

void printArray(int arr[], int s);

/*
Print array: 0,0,0,0,0,0,
Print array: 2,5,6,
       k:  i,  j
Round  5:  2,  1
Round  4:  2,  0
Round  3:  2, -1
Round  2:  2, -2
Round  1:  2, -3
Round  0:  2, -4
Print array: 0,1,0,2,5,6,

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    if (n==0) return;
    if (m==0) {
        for (int i=0; i<n; i++)
            nums1[i] = nums2[i];
        return;
    }

    int i=m-1, j=n-1;
    printf("       k:  i,  j\n");
    for (int k=m+n-1; k>=0; k--) {
        // printf("%d, %d\n", nums1[i], nums2[j]);
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i--];
        } else {
            nums1[k] = nums2[j--];
        }
        printf("Round % 2d: % 2d, % 2d\n", k, i, j);
    }
}
*/

// Please always make sure index is within boundary
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    if (n==0) return;
    if (m==0) {
        for (int i=0; i<n; i++)
            nums1[i] = nums2[i];
        return;
    }

    int i=m-1, j=n-1, k=m+n-1;
    while (i>=0&&j>=0) {
        if (nums1[i]>nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    while (j>=0) nums1[k--] = nums2[j--];
}

int main(int argc, char const *argv[]) {
    int arr1[] = {0, 0, 0, 0, 0, 0};
    int arr2[] = {2, 5, 6};
    printArray(arr1, arrSize(arr1));
    printArray(arr2, arrSize(arr2));

    merge(arr1, arrSize(arr1), 3, arr2, arrSize(arr2), 3);

    printArray(arr1, arrSize(arr1));
    return 0;
}

void printArray(int arr[], int s) {
    printf("Print array: ");
    for (int i = 0; i < s; i++) {
        printf("%d,", arr[i]);
    }
    printf("\n");
}
