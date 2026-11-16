/*
Find the starting point in LL
Given the head of a singly linked list, the task is to find the starting point of a loop in the linked list if it exists. Return the starting node if a loop exists; otherwise, return null.



A loop exists in a linked list if some node in the list can be reached again by continuously following the next pointer. Internally, pos denotes the index (0-based) of the node from where the loop starts.



Note that pos is not passed as a parameter.

*/
#include <iostream>

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
//Function to find the first node
//Of the loop in a linked list
    ListNode* findStartingPoint(ListNode* head) {
        //Initialize a slow and fast 
        //Pointers to the head of the list
        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: Detect the loop
        while (fast != NULL && fast->next != NULL) {
            
            // Move slow one step
            slow = slow->next;
            
            // Move fast two steps
            fast = fast->next->next;

            // If slow and fast meet,
            // a loop is detected
            if (slow == fast) {
                
                // Reset the slow pointer
                // To the head of the list
                slow = head;

                // Phase 2: Find the first node of the loop
                while (slow != fast) {
                    
                    // Move slow and fast one step
                    // At a time
                    slow = slow->next;
                    fast = fast->next;

                    // When slow and fast meet again,
                    // It's the first node of the loop
                }
                
                // Return the first node of the loop
                return slow;
            }
        }
        
        //If no loop is found, 
        //Return NULL
        return NULL;
    }
};

int main() {
    // Create a sample linked list with a loop
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    node1->next = node2;
    ListNode* node3 = new ListNode(3);
    node2->next = node3;
    ListNode* node4 = new ListNode(4);
    node3->next = node4;
    ListNode* node5 = new ListNode(5);
    node4->next = node5;

    // Make a loop from node5 to node2
    node5->next = node2;

    // Set the head of the linked list
    ListNode* head = node1;

    // Detect the loop in the linked list
    Solution sol;
    ListNode* loopStartNode = sol.findStartingPoint(head);

    if (loopStartNode) {
        cout << "Loop detected. Starting node of the loop is: " << loopStartNode->val << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    // Clean up memory (free the allocated nodes)
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;

    return 0;
}
