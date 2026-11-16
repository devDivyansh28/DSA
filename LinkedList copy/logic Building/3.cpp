/*Sort a Linked List of 0's 1's and 2's*/
/*
Given the head of a singly linked list consisting of only 0, 1 or 2.



Sort the given linked list and return the head of the modified list.



Do it in-place by changing the links between the nodes without creating new nodes.


Example 1

Input: linkedList = [1, 0, 2, 0 , 1]

Output: [0, 0, 1, 1, 2]

Explanation: The values after sorting are [0, 0, 1, 1, 2].

Example 2

Input: linkedList = [1, 1, 1, 0]

Output: [0, 1, 1, 1]

Explanation: The values after sorting are [0, 1, 1, 1].
*/
#include <bits/stdc++.h>

using namespace std;

// Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

class Solution {
public:
    // Function to sort the linked list
    ListNode* sortList(ListNode* head) {
       /* If the list is empty or has only one 
       node, return as it is already sorted*/
        if (head == NULL || head->next == NULL)
            return head;

        // Dummy nodes to point to heads of 
        // three lists
        ListNode* zeroHead = new ListNode(-1);
        ListNode* oneHead = new ListNode(-1);
        ListNode* twoHead = new ListNode(-1);

        // Pointers to current last nodes of 
        // three lists
        ListNode* zero = zeroHead;
        ListNode* one = oneHead;
        ListNode* two = twoHead;
        ListNode* temp = head;

       /* Traverse the original list 
       and distribute the nodes 
       into three lists*/
        while (temp != NULL) {
            if (temp->data == 0) {
                zero->next = temp;
                zero = temp;
            } else if (temp->data == 1) {
                one->next = temp;
                one = temp;
            } else if (temp->data == 2) {
                two->next = temp;
                two = temp;
            }
            temp = temp->next;
        }
        
        // Connect the three lists together
        zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = NULL;

        // New head of the sorted list
        ListNode* newHead = zeroHead->next;

        // Delete dummy nodes
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return newHead;
    }
};

// Function to print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to create new node
ListNode* newNode(int data) {
    ListNode* node = new ListNode(data);
    return node;
}

int main() {
    // Creating a linked list
    ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(0);
    head->next->next->next = newNode(1);
    head->next->next->next->next = newNode(2);
    head->next->next->next->next->next = newNode(0);
    head->next->next->next->next->next->next = newNode(1);

    // Print original list
    cout << "Original list: ";
    printList(head);

    // Sort the list
    Solution sol;
    head = sol.sortList(head);

    // Print sorted list
    cout << "Sorted list: ";
    printList(head);

    return 0;
}
