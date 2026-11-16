#include <bits/stdc++.h>
using namespace std;

// ListNode definition
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

// Solution class
class Solution {
public:
    // Function to insert a new node before the given node
    ListNode* insertBeforeX(ListNode* &head, int X, int val) {
        if (head == NULL) {
            return NULL;
        }

        /* Insert at the beginning if the 
        value matches the head's data */
        if (head->data == X)
            return new ListNode(val, head);

        ListNode* temp = head;
        while (temp->next != NULL) {
            /* Insert at the current position if the 
            next node has the desired value */
            if (temp->next->data == X) {
                ListNode* newNode = new ListNode(val, temp->next);
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};

// Helper Function to print the linked list
void printLL(ListNode* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list from a vector
    vector<int> arr = {1, 2, 4, 5};
    int X = 4, val = 3;
    ListNode* head = new ListNode(arr[0]);
    head->next = new ListNode(arr[1]);
    head->next->next = new ListNode(arr[2]);
    
    // Print the original list
    cout << "Original List: ";
    printLL(head);
    
    // Create a Solution object 
    Solution sol;
    head = sol.insertBeforeX(head, X, val);

    // Print the modified linked list
    cout << "List after inserting a new node before the given node: ";
    printLL(head);

    return 0;
}