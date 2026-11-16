#include <bits/stdc++.h>
using namespace std;

// Definition for doubly-linked list.
class ListNode {
public:
    int data;
    ListNode *prev;
    ListNode *next;
    ListNode() : data(0), prev(nullptr), next(nullptr) {}
    ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
    ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};

// Solution class
class Solution {
public:
    // Function to convert an array to a doubly linked list
    ListNode* arrayToDoublyLinkedList(vector<int> &arr) {
        // If array is empty, return nullptr
        if (arr.empty()) return nullptr; 

        // Create head node with first element of the array
        ListNode* head = new ListNode(arr[0]); 
        
        // Initialize 'prev' to the head node
        ListNode* prev = head;             

        for (int i=1; i < arr.size(); i++) {
            // Create a new node 
            ListNode* temp = new ListNode(arr[i], prev, nullptr);
            // Update 'next' pointer
            prev->next = temp;    
            // Move 'prev' to newly created node
            prev = temp;         
        }
        
        // Return head
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
    vector<int> nums = {1, 2, 3, 4};
    
    // Create an instance of Solution class 
    Solution sol;
    
    // Function call to convert an array to a doubly linked list
    ListNode* head = sol.arrayToDoublyLinkedList(nums);

    // Print the doubly linked list
    cout << "The doubly linked list is: ";
    printLL(head);

    return 0;
}