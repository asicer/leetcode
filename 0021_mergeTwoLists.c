#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define arraySize(arr) sizeof(arr)/sizeof(*arr)

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (!l1) return l2;
    if (!l2) return l1;
    struct ListNode *p1=l1, *p2=l2;
    struct ListNode* head = NULL, *tail = NULL;
    if (l1->val < l2->val) {
        head = p1;
        p1 = p1->next;
    } else {
        head = p2;
        p2 = p2->next;
    }
    tail = head;
    while (p1 && p2) {
        if (p1->val < p2->val) {
            tail->next = p1;
            tail = tail->next;
            p1 = p1->next;

        } else {
            tail->next = p2;
            tail = tail->next;
            p2 = p2->next;
        }
    }
    tail->next = p1 ? p1 : p2;
    return head;
}

struct ListNode* createLinkedList(int arr[], int size);
void printLinkedList(struct ListNode* p);

int main(int argc, char const *argv[]) {
    int arr1[] = {1, 5, 6, 9};
    int arr2[] = {0, 2, 3, 4, 5, 6, 7, 8};
    struct ListNode* p1 = createLinkedList(arr1, arraySize(arr1));
    struct ListNode* p2 = createLinkedList(arr2, arraySize(arr2));
    printLinkedList(p1);
    printLinkedList(p2);
    struct ListNode* p3 = mergeTwoLists(p1, p2);
    printLinkedList(p3);
    return 0;
}

struct ListNode* createLinkedList(int arr[], int size) {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode*)), *tail=head, *temp;
    head->val = arr[0];
    head->next = NULL;

    for (int i=1; i<size; i++) {
        temp = (struct ListNode*)malloc(sizeof(struct ListNode*));
        temp->val = arr[i];
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
    return head;
}

void printLinkedList(struct ListNode* p) {
    while (p) {
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");
}
