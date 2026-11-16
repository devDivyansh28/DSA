/*
Clone a LL with random and next pointer

Given the head of a special linked list of n nodes where each node contains an additional pointer called 'random' which can point to any node in the list or null.



Construct a deep copy of the linked list where,

n new nodes are created with corresponding values as original linked list.
The random pointers point to the corresponding new nodes as per their arrangement in the original list.
Return the head of the newly constructed linked list.


Note: For custom input, a n x 2 matrix is taken with each row having 2 values:[ val, random_index] where,

val: an integer representing ListNode.val
random_index: index of the node (0 - n-1) that the random pointer points to, otherwise -1.

Example 1

Input: [[1, -1], [2, 0], [3, 4], [4, 1], [5, 2]]

Output: 1 2 3 4 5, true

Explanation: All the nodes in the new list have same corresponding values as original nodes.

All the random pointers point to their corresponding nodes in the new list.

'true' represents that the nodes and references were created new.

Example 2

Input: [[5, -1], [3, -1], [2, 1], [1, 1]]

Output: 5 3 2 1, true

Explanation: All the nodes in the new list have same corresponding values as original nodes.

All the random pointers point to their corresponding nodes in the new list.

'true' represents that the nodes and references were created new.

[[5, -1], [3, -1], [2, -1], [1, -1]] will be incorrect, although it has the same values.
*/

#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode *random;
    ListNode() {
        val = 0;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1) {
        val = data1;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* r) {
        val = data1;
        next = next1;
        random = r;
    }
};

class Solution {
public:
    // Insert a copy of each node in between the original nodes
    void insertCopyInBetween(ListNode* head) {
        ListNode* temp = head;
        while (temp != NULL) {
            ListNode* nextElement = temp->next;
            // Create a new node with the same data
            ListNode* copy = new ListNode(temp->val);
            
            copy->next = nextElement;
            
            temp->next = copy;
            
            temp = nextElement;
        }
    }

    // Function to connect random pointers of the copied nodes
    void connectRandomPointers(ListNode* head) {
        ListNode* temp = head;
        while (temp != NULL) {
            // Access the copied node
            ListNode* copyNode = temp->next;
            
            /*If the original node has a random pointer
            point the copied node's random to the 
            corresponding copied random node
            set the copied node's random to null 
            if the original random is null*/
            if (temp->random) {
                
                copyNode->random = temp->random->next;
            } else {
                
                copyNode->random = NULL;
            }
            
            // Move to next original node
            temp = temp->next->next;
        }
    }

    // Function to retrieve the deep copy of the linked list
    ListNode* getDeepCopyList(ListNode* head) {
        ListNode* temp = head;
        // Create a dummy node
        ListNode* dummyNode = new ListNode(-1);
        // Initialize a result pointer
        ListNode* res = dummyNode;

        while (temp != NULL) {
            /*Creating a new List by 
            pointing to copied nodes*/
            res->next = temp->next;
            res = res->next;

            /*Disconnect and revert back 
            to the initial state of the 
            original linked list*/
            temp->next = temp->next->next;
            temp = temp->next;
        }
        
        /*Return the deep copy 
        of the list starting 
        from the dummy node*/
        return dummyNode->next;
    }

    // Function to clone the linked list
    ListNode* copyRandomList(ListNode* head) {
        // If the original list is empty, return null
        if (!head) return nullptr;

        // Insert nodes in between
        insertCopyInBetween(head);
        // Connect random pointers
        connectRandomPointers(head);
        // Retrieve deep copy of inked list
        return getDeepCopyList(head);
    }
};

// Function to print the cloned linked list
void printClonedLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << "Data: " << head->val;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->val;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
        // Move to the next node
        head = head->next;
    }
}

int main() {
    // Example linked list: 7 -> 14 -> 21 -> 28
    ListNode* head = new ListNode(7);
    head->next = new ListNode(14);
    head->next->next = new ListNode(21);
    head->next->next->next = new ListNode(28);

    // Assigning random pointers
    head->random = head->next->next; // 7 -> 21
    head->next->random = head; // 14 -> 7
    head->next->next->random = head->next->next->next; // 21 -> 28
    head->next->next->next->random = head->next; // 28 -> 14

    // Print the original linked list
    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);

    // Clone the linked list
    Solution solution;
    ListNode* clonedList = solution.copyRandomList(head);

    // Print the cloned linked list
    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(clonedList);

    return 0;
}
