/*
Rotate a LL
Given the head of a singly linked list containing integers, shift the elements of the linked list to the right by k places and return the head of the modified list. Do not change the values of the nodes, only change the links between nodes.


Example 1

Input: head -> 1 -> 2 -> 3 -> 4 -> 5, k = 2

Output: head -> 4 -> 5 -> 1 -> 2 -> 3

Explanation:

List after 1 shift to right: head -> 5 -> 1 -> 2 -> 3 -> 4.

List after 2 shift to right: head -> 4 -> 5 -> 1 -> 2 -> 3.

Example 2

Input: head -> 1 -> 2 -> 3 -> 4 -> 5, k = 4

Output: head -> 2 -> 3 -> 4 -> 5 -> 1

Explanation:

List after 1 shift to right: head -> 5 -> 1 -> 2 -> 3 -> 4.

List after 2 shift to right: head -> 4 -> 5 -> 1 -> 2 -> 3.

List after 3 shift to right: head -> 3 -> 4 -> 5 -> 1 -> 2.

List after 4 shift to right: head -> 2 -> 3 -> 4 -> 5 -> 1.
*/
#include <iostream>
using namespace std;

// Definition of singly linked list
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode() {
        val = 0;
        next = nullptr;
    }
    ListNode(int data1) {
        val = data1;
        next = nullptr;
    }
    ListNode(int data1, ListNode* next1) {
        val = data1;
        next = next1;
    }
};

class Solution {
public:
    // Function to rotate the list by k steps
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) 
            return head;

        // Calculating length
        ListNode* temp = head;
        int length = 1;
        while (temp->next != nullptr) {
            ++length;
            temp = temp->next;
        }

        // Link last node to first node
        temp->next = head;
        // When k is more than length of list
        k = k % length; 
        // To get end of the list
        int end = length - k; 
        while (end-- > 0) 
            temp = temp->next;

        // Breaking last node link and pointing to NULL
        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};

// Utility function to insert node at the end of the list
void insertNode(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = newNode;
}

// Utility function to print list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    // Inserting nodes
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);

    cout << "Original list: ";
    printList(head);

    int k = 2;
    Solution solution;
    // Calling function for rotating right by k times
    ListNode* newHead = solution.rotateRight(head, k);

    cout << "After " << k << " iterations: ";
    // List after rotating nodes
    printList(newHead);

    return 0;
}