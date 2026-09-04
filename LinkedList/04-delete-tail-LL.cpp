#include <bits/stdc++.h>
using namespace std;

// Node structure
struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int data1): val(data1), next(nullptr) {}
    ListNode(int data1, ListNode *next1): val(data1), next(next1) {}
};

class Solution {
public:
    // Function to delete the tail node of linked list 
    ListNode* deleteTail(ListNode* head) {
        
        // If the list is empty or has only one node
        if (head == NULL || head->next == NULL)
            return NULL; // Return NULL
        
        // Temporary pointer
        ListNode* temp = head;
        
        /*Traverse to the second last
        node in the list*/
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        
        // Delete the last node
        delete temp->next;
        
        /*Set the next of the second 
        last node to nullptr, 
        effectively removing the last node*/
        temp->next = nullptr;
        
        // Return head of modified list
        return head;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to insert a new node at the beginning of the linked list
ListNode* insertAtHead(ListNode* head, int data) {
    ListNode* newNode = new ListNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

int main() {
    // Create a linked list
    ListNode* head = nullptr;
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 1);

    cout << "Original list: ";
    printList(head);
    
    // Creating an instance of Solution Class
    Solution sol;
    
    // Function call to delete the tail node
    head = sol.deleteTail(head);

    cout << "List after deleting head: ";
    printList(head);

    return 0;
}