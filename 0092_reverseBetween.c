#include <stdlib.h>

#define arraySize(arr) sizeof(arr)/sizeof(*arr)

struct ListNode* createLinkedList(int arr[], int size);
void printLinkedList(struct ListNode* p);

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if (!head || m==n) return head;
    struct ListNode *pm = head, *prev=NULL, *p0, *p1, *p2, *tail;
    for (int i=0; i<m-1; i++) {
        prev = pm;
        pm = pm->next;
    }
    p0 = NULL;
    tail = pm;
    for (int i=0; i<n-m+1; i++) {
        p1 = pm;
        p2 = pm->next;

        p1->next = p0;
        p0 = p1;
        p1 = p2;

        pm = p2;
    }

    tail->next = pm;

    if (prev) {
        prev->next = p0;
        return head;
    } else {
        return p0;
    }
}

int main(int argc, char const *argv[]) {
    int m, n;

    int arr1[] = {1, 2, 3, 4, 5};
    struct ListNode* p1 = createLinkedList(arr1, arraySize(arr1));
    m = 2, n = 3;

    printLinkedList(p1);
    printf("Swap between %d, %d\n", m, n);
    printLinkedList(reverseBetween(p1, m, n));

    printf("\n");

    int arr2[] = {1, 2, 3, 4, 5};
    struct ListNode* p2 = createLinkedList(arr2, arraySize(arr2));
    m = 1, n = 3;

    printLinkedList(p2);
    printf("Swap between %d, %d\n", m, n);
    printLinkedList(reverseBetween(p2, m, n));

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
