/*
Reverse a LL
Given the head of a singly linked list. Reverse the given linked list and return the head of the modified list.

Example 1

Input: head -> 1 -> 2 -> 3 -> 4 -> 5

Output: head -> 5 -> 4 -> 3 -> 2 -> 1

Explanation: All the links are reversed and the head now points to the last node of the original list.

Example 2

Input: head -> 6 -> 8

Output: head -> 8 -> 6

Explanation: All the links are reversed and the head now points to the last node of the original list.

This can be seen like: 6 <- 8 <- head.
*/


#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
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

class Solution {
public:
    /* Function to reverse a singly linked list using recursion */
    ListNode* reverseList(ListNode* head) {
        /* Base case:
        If the linked list is empty or has only one node,
        return the head as it is already reversed. */
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        /* Recursive step:
        Reverse the linked list starting 
        from the second node (head->next). */
        ListNode* newHead = reverseList(head->next);
        
        /* Save a reference to the node following
        the current 'head' node. */
        ListNode* front = head->next;
        
        /* Make the 'front' node point 
        to the current
        'head' node in the 
        reversed order. */
        front->next = head;
        
        /* Break the link from 
        the current 'head' node
        to the 'front' node 
        to avoid cycles. */
        head->next = NULL;
        
        /* Return the 'newHead,' 
        which is the new
        head of the reversed 
        linked list. */
        return newHead;
    }
};

// Function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list with values 1, 3, 2, and 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(4);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Solution instance
    Solution sol;
    // Reverse the linked list
    head = sol.reverseList(head);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}
