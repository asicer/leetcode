#include <stdlib.h>

#define arraySize(arr) sizeof(arr)/sizeof(*arr)

struct ListNode* createLinkedList(int arr[], int size);
void printLinkedList(struct ListNode* p);

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head){
    if (!head || !head->next) return head;

    struct ListNode *p0=NULL, *p1, *p2, *p = head;

    while (p) {
        p1 = p;
        p2 = p->next;

        p1->next = p0;
        p0 = p1;
        p1 = p2;

        // p = p->next;
        p = p2;
        // printLinkedList(p0);
    }

    return p0;
}

int main(int argc, char const *argv[]) {
    int arr1[] = {1, 2, 3, 4};
    struct ListNode* p1 = createLinkedList(arr1, arraySize(arr1));

    printLinkedList(p1);
    printLinkedList(reverseList(p1));

    int arr2[] = {1, 5, 6, 7, 9};
    struct ListNode* p2 = createLinkedList(arr2, arraySize(arr2));

    printLinkedList(p2);
    printLinkedList(reverseList(p2));

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
