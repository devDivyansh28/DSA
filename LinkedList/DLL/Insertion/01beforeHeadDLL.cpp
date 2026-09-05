#include <bits/stdc++.h>
using namespace std;

// Definition of doubly linked list
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
    /* Function to insert a node before 
    head in a doubly linked list */
    ListNode* insertBeforeHead(ListNode* head, int X) {
        // Create new node which will be the new head
        ListNode* newHead = new ListNode(X, nullptr, head);
        
        // Point the current head back to new one
        head->prev = newHead;

        return newHead; // Return new head
    }
};

// Helper Function to convert an array to a doubly linked list
ListNode* arrayToLinkedList(vector<int> &nums) {
    // If array is empty, return nullptr
    if (nums.empty()) return nullptr; 

    // Create head node with first element of the array
    ListNode* head = new ListNode(nums[0]); 
    // Initialize 'prev' to the head node
    ListNode* prev = head;             

    for (int i=1; i < nums.size(); i++) {
        // Create a new node 
        ListNode* temp = new ListNode(nums[i], prev, nullptr);
        // Update 'next' pointer
        prev->next = temp;    
        // Move 'prev' to newly created node
        prev = temp;         
    }
    
    // Return head
    return head;  
}

// Helper Function to print the linked list
void printLL(ListNode* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> nums = {2, 3, 4, 5};
    
    // Creating the doubly linked list from given array
    ListNode* head = arrayToLinkedList(nums);
    
    // Print the Original list 
    cout << "Original List: ";
    printLL(head);
    
    // Create an instance of Solution class 
    Solution sol;
    
    /* Function call to insert a node before 
    head in a doubly linked list */
    head = sol.insertBeforeHead(head, 1);
    
    // Print the Modified list
    cout << "Modified list: ";
    printLL(head);

    return 0;
}