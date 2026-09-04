#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

// Solution class
class Solution {
public:
    // Function to insert a new node at the tail of the linked list
    ListNode* insertAtTail(ListNode* &head, int X) {
        if (head == NULL)
            return new ListNode(X);

        ListNode* temp = head;
        // Traversing until the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        ListNode* newNode = new ListNode(X);
        temp->next = newNode;

        return head;
    }
};

// Helper Function to print the linked list
void printLL(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list from a vector
    vector<int> arr = {10, 20, 30};
    int val = 40;
    ListNode* head = new ListNode(arr[0]);
    head->next = new ListNode(arr[1]);
    head->next->next = new ListNode(arr[2]);
    
    // Print the original list
    cout << "Original List: ";
    printLL(head);
    
    // Create a Solution object 
    Solution sol;
    head = sol.insertAtTail(head, val);

    // Print the modified linked list
    cout << "List after inserting the given value at the tail:";
    printLL(head);

    return 0;
}