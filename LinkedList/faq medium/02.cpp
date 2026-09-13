/*
Find Middle of Linked List
Given the head of a singly Linked List, return the middle node of the Linked List.



If the Linked List has an even number of nodes, return the second middle one.


Example 1

Input: head -> 3 -> 8 -> 7 -> 1 -> 3

Output(value at returned node): 7

Explanation: There are 5 nodes, so the middle node is the 3rd Node, with value 7.

Example 2

Input: head -> 2 -> 9 -> 1 -> 4 -> 0 -> 4

Output(value at returned node): 4

Explanation: There are 6 nodes, thus both the 3rd and 4th nodes are middle. So the 2nd middle node (4th Node) is returned with value 4.

Now your turn!

Input: head -> 3 -> 8 -> 1 -> 7 -> 0
*/

#include <bits/stdc++.h>
using namespace std;

//Definition of singly linked list:
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
    // Function to get the middle node of linked list
    ListNode* middleOfLinkedList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Until the fast pointers reaches NULL or the last node
        while(fast != NULL && fast->next != NULL) {
            // Move slow pointer by one step
            slow = slow-> next;
            
            // Move fast pointer by two steps
            fast = fast->next-> next;
        }
        
        return slow;
    }
};

// Utility Function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    
    // Traverse the linked list and print each node's value
    while (temp != nullptr) { 
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating a simple linked list
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    // Creating an object of Solution class
    Solution sol;
    
    // Function call to get the middle node of linked list 
    ListNode* middleNode = sol.middleOfLinkedList(head);
    
    printLinkedList(head);
    cout << "The middle node is: " << middleNode->val << endl;

    return 0;
}
