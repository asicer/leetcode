#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define arrSize(arr) sizeof(arr)/sizeof(*arr)

void printArray(int arr[], int s);

int lengthOfLastWord(char * s){
    int sSize = strlen(s);
    int i=sSize-1;

    while (i>=0) {
        if (s[i--] == ' ') {
            sSize--;
        } else {
            break;
        }
    }
    for (; i>=0; i--) {
        if (s[i] == ' ') {
            break;
        }
    }
    return sSize-i-1;
}

int main(int argc, char const *argv[]) {
    printf("Return size: %d\n", lengthOfLastWord("   "));
    printf("Return size: %d\n", lengthOfLastWord("a   "));
    printf("Return size: %d\n", lengthOfLastWord("Hello World"));

    return 0;
}

void printArray(int arr[], int s) {
    printf("Print array: ");
    for (int i = 0; i < s; i++) {
        printf("%d,", arr[i]);
    }
    printf("\n");
}
