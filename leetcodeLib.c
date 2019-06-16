#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(*arr)

struct ListNode {
    int val;
    struct ListNode *next;
};

// Array 
void printArray(int arr[], int arrSize);
// LinkedList
struct ListNode* createList(int arr[], int arrSize);
void insertData(struct ListNode *list, int data);
void printList(struct ListNode* list);
// Bitwise
void printBinary(int n);

// Array 
void printArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// LinkedList
struct ListNode* createList(int arr[], int arrSize) {
    struct ListNode* list = malloc(sizeof(struct ListNode));
    list->val = arr[0];
    list->next = NULL;

    struct ListNode* head = list;
    struct ListNode* p;

    for (int i = 1; i < arrSize; i++) {
        p = malloc(sizeof(struct ListNode));
        p->val = arr[i];
        p->next = NULL;
        list->next = p;
        list = list->next;
    }
    return head;
}

void printList(struct ListNode* list) {
    if (list == NULL) return;
    struct ListNode* p = list;
    while (p) {
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");
}

// Bitwise
void printBinary(int n) {
    while (n) {
        int bit = n&0x1;
        n >>= 1;
        printf("%d", bit);
    }
    printf("\n");
}
