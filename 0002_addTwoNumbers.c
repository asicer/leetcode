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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if (!l2) return l1;
    if (!l1) return l2;

    int value = 0, carry = 0;
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    value = l1->val + l2->val + carry;
    head->val = value%10;
    head->next = NULL;
    carry = value/10;

    struct ListNode *tail = head;
    struct ListNode *temp;

    l1 = l1->next;
    l2 = l2->next;
    while (l1 && l2) {
        value = l1->val + l2->val + carry;
        carry = value/10;

        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = value%10;
        temp->next = NULL;

        tail->next = temp;
        tail = temp;

        l1 = l1->next;
        l2 = l2->next;
    }

    struct ListNode *p  = l1 ? l1 : l2;
    while (p) {
        value = p->val + carry;
        carry = value/10;
        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = value%10;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
        p = p->next;
    }

    if (carry == 1) {
        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = 1;
        temp->next = NULL;
        tail->next = temp;
    }

    return head;
}

struct ListNode* createLinkedList(int arr[], int size);
void printLinkedList(struct ListNode* p);

int main(int argc, char const *argv[]) {
    int arr1[] = {2, 4, 3};
    int arr2[] = {9, 9, 9};
    struct ListNode* p1 = createLinkedList(arr1, arraySize(arr1));
    struct ListNode* p2 = createLinkedList(arr2, arraySize(arr2));
    printLinkedList(p1);
    printLinkedList(p2);
    struct ListNode* p3 = addTwoNumbers(p1, p2);
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
