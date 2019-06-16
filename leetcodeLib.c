#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(*arr)

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} LinkedList;

// Array 
void printArray(int arr[], int arrSize);
// LinkedList
LinkedList* createList(int arr[], int arrSize);
void insertData(LinkedList *list, int data);
void printList(LinkedList* list);
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
LinkedList* createList(int arr[], int arrSize) {
    LinkedList* list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    for (int i = 0; i < arrSize; i++) {
        insertData(list, arr[i]);
    }
    return list;
}

void insertData(LinkedList* list, int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

void printList(LinkedList* list) {
    Node* p = list->head;
    while (p != NULL) {
        printf("%d -> ", p->data);
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
