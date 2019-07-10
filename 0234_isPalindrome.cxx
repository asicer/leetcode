#include <stack>
#include <vector>
#include <iostream>
using namespace std;

#define arraySize(arr) sizeof(arr)/sizeof(*arr)
struct ListNode* createLinkedList(int arr[], int size);
void printLinkedList(struct ListNode* p);

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        stack<int> s1;
        struct ListNode *slow=head, *fast=head;
        while (fast && fast->next) {
            s1.push(slow->val);

            slow = slow->next;
            fast = fast->next->next;
        }
        slow = fast ? slow->next : slow;

        while (slow) {
            if (slow->val != s1.top()) {
                return false;
            }
            s1.pop();
            slow = slow->next;
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    Solution slu;

    int arr[] = {1, 2, 3, 3, 2, 1};
    struct ListNode* p = createLinkedList(arr, arraySize(arr));
    printLinkedList(p);

    bool b = slu.isPalindrome(p);
    cout << "Result is: " << b << endl;
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
        cout << p->val << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}
