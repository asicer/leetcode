#include <stdlib.h>

#define arraySize(arr) sizeof(arr)/sizeof(*arr)

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head){
    if (!head || !head->next) return head;

    struct ListNode *first, *second, *tail, *p = head;

    first = p;
    second = p->next;
    if (p->next)
        p = p->next->next;

    head = second;
    head->next = first;
    tail = first;

    while (p && p->next) {
        first = p;
        second = p->next;
        if (p->next)
            p = p->next->next;

        tail->next = second;
        tail = tail->next;
        tail->next = first;
        tail = tail->next;
    }

    tail->next = p ? p : NULL;

    return head;
}

struct ListNode* createLinkedList(int arr[], int size);
void printLinkedList(struct ListNode* p);

int main(int argc, char const *argv[]) {
    int arr1[] = {5, 6, 7, 9};
    struct ListNode* p1 = createLinkedList(arr1, arraySize(arr1));

    printLinkedList(p1);
    printLinkedList(swapPairs(p1));

    int arr2[] = {1, 5, 6, 7, 9};
    struct ListNode* p2 = createLinkedList(arr2, arraySize(arr2));

    printLinkedList(p2);
    printLinkedList(swapPairs(p2));

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
