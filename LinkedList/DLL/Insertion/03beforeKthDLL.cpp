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
    /* Function to insert a node before the
    Kth node in a doubly linked list */
    ListNode* insertBeforeKthPosition(ListNode* head, int X, int K) {
        // If node has to be inserted before the head
        if (K == 1) {
            ListNode* newHead = new ListNode(X, nullptr, head);
            head->prev = newHead;
            return newHead;
        }

        // Temporary pointer 
        ListNode* temp = head;

        // Reach kth node
        int count = 0;
        while (temp != nullptr) {
            count++;
            
            // If kth node is reached, Break out of the loop
            if (count == K) break;
            
            // Otherwise Keep moving temp forward
            temp = temp->next;
        }
        
        // Track the node 
        ListNode* prev = temp->prev;

        // Create new node with data as X
        ListNode* newNode = new ListNode(X, prev, temp);

        // Join new node 
        prev->next = newNode;
        temp->prev = newNode;

        // Return head 
        return head;
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
    vector<int> nums = {1, 2, 3, 5};
    
    // Creating the doubly linked list from given array
    ListNode* head = arrayToLinkedList(nums);
    
    // Print the Original list 
    cout << "Original List: ";
    printLL(head);
    
    // Create an instance of Solution class 
    Solution sol;
    
    /* Function call to insert a node before the
    Kth node in a doubly linked list */
    head = sol.insertBeforeKthPosition(head, 4, 4);
    
    // Print the Modified list
    cout << "Modified list: ";
    printLL(head);

    return 0;
}