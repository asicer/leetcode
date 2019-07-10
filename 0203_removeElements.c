#include <stdlib.h>
#include <stdbool.h>

#define arraySize(arr) sizeof(arr)/sizeof(*arr)

struct ListNode* createLinkedList(int arr[], int size);
void printLinkedList(struct ListNode* p);

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val){
    while (head) {
        if (head->val != val)
            break;
        head = head->next;
    }
    struct ListNode *p = head;
    while (p && p->next) {
        if (p->next->val == val)
            p->next = p->next->next;
        else
            p = p->next;
    }
    return head;
}

int main(int argc, char const *argv[]) {
    // int arr1[] = {1, 2, 2, 1};
    int arr1[] = {1, 1, 3, 1, 1, 5, 3, 5, 1};
    struct ListNode* p1 = createLinkedList(arr1, arraySize(arr1));

    printLinkedList(p1);
    printLinkedList(removeElements(p1, 1));

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
