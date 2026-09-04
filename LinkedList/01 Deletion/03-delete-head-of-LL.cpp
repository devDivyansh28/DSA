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
    // Function to delete the head node of the linked list
    ListNode* deleteHead(ListNode* head) {
        // If list is empty, nothing to delete
        if (head == nullptr) 
            return nullptr; 
        
        // Set temporary pointer
        ListNode* temp = head; 
        
        // Update head to the next node 
        head = head->next;  
        
        // Delete original head    
        delete temp; 
        
        // Return new head          
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
    
    // Function call to delete the head node
    head = sol.deleteHead(head);

    cout << "List after deleting head: ";
    printList(head);

    return 0;
}