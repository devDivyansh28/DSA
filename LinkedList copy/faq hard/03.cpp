/*
Merge two Sorted Lists
Given the heads of two linked lists, list1 and list2, where each linked list has its elements sorted in non-decreasing order, merge them into a single sorted linked list and return the head of the merged linked list.


Example 1

Input: list1 = head -> 2 -> 4 -> 7 -> 9, list2 = head -> 1 -> 2 -> 5 -> 6

Output: head -> 1 -> 2 -> 2 -> 4 -> 5 -> 6 ->7 -> 9

Explanation: head -> 1 -> 2 -> 2 -> 4 -> 5 -> 6 ->7 -> 9, the underlined nodes come from list2, the others come from list1.

Example 2

Input: list1 = head -> 1 -> 2 -> 3 -> 4, list2 = head -> 5 -> 6 -> 10

Output: head -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 10

Explanation: head -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 10, the underlined nodes come from list2, the others come from list1.
*/

#include <bits/stdc++.h>

using namespace std;

// Definition of singly linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int data1) {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1) {
        val = data1;
        next = next1;
    }
};

class Solution {
public:
    // Function to merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to serve as 
        // the head of the merged list
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        // Traverse both lists simultaneously
        while (list1 != nullptr && list2 != nullptr) {
            /*Compare elements of both lists 
            and link the smaller node 
            to the merged list*/
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            // Move the temporary pointer 
            // to the next node
            temp = temp->next;
        }

        /*If any list still 
        has remaining elements, 
        append them to the merged list*/
        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        // Return merged list 
        return dummyNode->next;
    }
};

// Function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        // Print the data of the current node
        cout << temp->val << " ";
        // Move to the next node
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Example Linked Lists
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    cout << "First sorted linked list: ";
    printLinkedList(list1);

    cout << "Second sorted linked list: ";
    printLinkedList(list2);

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    cout << "Merged sorted linked list: ";
    printLinkedList(mergedList);

    return 0;
}
