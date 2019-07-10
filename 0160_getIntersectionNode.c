#include <stdlib.h>
#include <stdbool.h>

#define arraySize(arr) sizeof(arr)/sizeof(*arr)

struct ListNode* createLinkedList(int arr[], int size);
void printLinkedList(struct ListNode* p);

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *pa = headA, *pb = headB;
    while (pa != pb) {
        pa = !pa ? headB : pa->next;
        pb = !pb ? headA : pb->next;
    }
    return pa;
}

int main(int argc, char const *argv[]) {
    int arr1[] = {1, 3, 2};
    int arr2[] = {4, 6};
    int arr3[] = {7, 3, 8};
    struct ListNode *p1 = createLinkedList(arr1, arraySize(arr1));
    struct ListNode *p2 = createLinkedList(arr2, arraySize(arr2));
    struct ListNode *p3 = createLinkedList(arr3, arraySize(arr3));

    struct ListNode *p0;

    // 1 3 2  7 3 8
    //   4 6  7 3 8
    p0 = p1;
    while (p0->next) {
        p0 = p0->next;
    }
    p0->next = p3;

    p0 = p2;
    while (p0->next) {
        p0 = p0->next;
    }
    p0->next = p3;

    printLinkedList(p1);
    printLinkedList(p2);

    printLinkedList(getIntersectionNode(p1, p2));

    printf("\n");

    return 0;
}

struct ListNode* createLinkedList(int arr[], int size) {
    if (size == 0) return NULL;

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
