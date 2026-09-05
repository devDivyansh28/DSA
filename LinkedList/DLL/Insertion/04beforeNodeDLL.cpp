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
    /* Function to insert a new node before
    given node in a doubly linked list */
    void insertBeforeGivenNode(ListNode* node, int X) {
        // Get node before the given node
        ListNode* prev = node->prev;
        
        // Create new node 
        ListNode* newNode = new ListNode(X, prev, node);
        
        // Connect newNode
        prev->next = newNode;
        node->prev = newNode;
        
        // void function to just update
        return;
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
    vector<int> nums = {1, 2, 4, 5};
    
    // Creating the doubly linked list from given array
    ListNode* head = arrayToLinkedList(nums);
    
    // Node before which the new node must be inserted
    ListNode* node = head-> next-> next;
    
    // Print the Original list 
    cout << "Original List: ";
    printLL(head);
    
    // Create an instance of Solution class 
    Solution sol;
    
    /* Function call to insert a new node before
    given node in a doubly linked list */
    sol.insertBeforeGivenNode(node, 3);
    
    // Print the Modified list
    cout << "Modified list: ";
    printLL(head);

    return 0;
}