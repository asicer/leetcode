#include <stdlib.h>

#define arraySize(arr) sizeof(arr)/sizeof(*arr)

struct ListNode* createLinkedList(int arr[], int size);
void printLinkedList(struct ListNode* p);

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *p = head;
    while (p && p->next) {
        while (p && p->next) {
            if (p->val == p->next->val) {
                p->next = p->next->next;
            } else {
                break;
            }
        }
        p = p->next;
    }
    return head;
}

int main(int argc, char const *argv[]) {
    // int arr1[] = {1, 3, 5};
    int arr1[] = {1, 1, 3, 5, 5};
    struct ListNode* p1 = createLinkedList(arr1, arraySize(arr1));

    printLinkedList(p1);
    printLinkedList(deleteDuplicates(p1));

    printf("\n");

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
