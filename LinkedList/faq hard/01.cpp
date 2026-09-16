/*
Reverse LL in group of given size K

Given the head of a singly linked list containing integers, reverse the nodes of the list in groups of k and return the head of the modified list. If the number of nodes is not a multiple of k, then the remaining nodes at the end should be kept as is and not reversed.



Do not change the values of the nodes, only change the links between nodes.


Example 1

Input: head -> 1 -> 2 -> 3 -> 4 -> 5, k = 2

Output: head -> 2 -> 1 -> 4 -> 3 -> 5

Explanation: The groups 1 -> 2 and 3 -> 4 were reversed as 2 -> 1 and 4 -> 3.

Example 2

Input: head -> 1 -> 2 -> 3 -> 4 -> 5, k = 3

Output: head -> 3 -> 2 -> 1 -> 4 -> 5

Explanation: The groups 1 -> 2 -> 3 were reversed as 3 -> 2 -> 1.

Note that 4 -> 5 was not reversed.

Example 3

Input: head -> 6 -> 1 -> 2 -> 3 -> 4 -> 7, k = 4

Output:

head -> 3 -> 2 -> 1 -> 6 -> 4 -> 7
Constraints

1 <= k <= number of nodes in the linked list <= 105
-104 <= ListNode.val <= 104
*/
#include <bits/stdc++.h>

using namespace std;

// Definition of singly linked list:
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
    // Function to reverse a linked list 
    // Using the 3-pointer approach
    ListNode* reverseLinkedList(ListNode *head)
    {
        /* Initialize 'temp' at 
         * head of linked list */
        ListNode* temp = head;
        
        /* Initialize pointer 'prev' 
         * to NULL, representing 
         * the previous node */
        ListNode* prev = NULL;
        
        // Continue till 'temp' 
        // reaches the end (NULL)
        while(temp != NULL){
            /* Store the next node in 'front' 
             * to preserve the reference */
            ListNode* front = temp->next;
            
            /* Reverse the direction of the 
             * current node's 'next' pointer 
             * to point to 'prev' */
            temp->next = prev;
            
            /* Move 'prev' to the current 
             * node for the next iteration */
            prev = temp;
            
            /* Move 'temp' to the 'front' node 
             * advancing the traversal */
            temp = front;
        }
        
        // Return the new head 
        // of the reversed linked list
        return prev;
    }

    // Function to get the Kth node from a 
    // given position in the linked list
    ListNode* getKthNode(ListNode* temp, int k){
        // Decrement K 
        // as we already start 
        // from the 1st node
        k -= 1;

        // Decrement K until it reaches the desired position
        while(temp != NULL && k > 0){
            // Decrement k as temp progresses
            k--;
            
            // Move to the next node
            temp = temp -> next;
        }
        
        // Return the Kth node
        return temp;
    }

    // Function to reverse nodes in groups of K
    ListNode* reverseKGroup(ListNode* head, int k){
        /* Initialize a temporary 
         * node to traverse the list */
        ListNode* temp = head;

        /* Initialize a pointer to track 
         * the last node of the previous group */
        ListNode* prevLast = NULL;
        
        // Traverse through the linked list
        while(temp != NULL){
            // Get the Kth node of the current group
            ListNode* kThNode = getKthNode(temp, k);

            /* If the Kth node is NULL 
             * (not a complete group) */
            if(kThNode == NULL){
                /* If there was a previous group, 
                 * link the last node to the current node */
                if(prevLast){
                    prevLast -> next = temp;
                }
                
                // Exit the loop
                break;
            }
            
            /* Store the next node 
             * after the Kth node */
            ListNode* nextNode = kThNode -> next;

            /* Disconnect the Kth node 
             * to prepare for reversal */
            kThNode -> next = NULL;

            // Reverse the nodes from temp to the Kth node
            reverseLinkedList(temp);
            
            /* Adjust the head if the reversal 
             * starts from the head */
            if(temp == head){
                head = kThNode;
            }else{
                /* Link the last node of the previous 
                 * group to the reversed group */
                prevLast -> next = kThNode;
            }

            /* Update the pointer to the 
             * last node of the previous group */
            prevLast = temp;

            // Move to the next group
            temp = nextNode;
        }
        
        // Return the head of the modified linked list
        return head;
    }
};

// Function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list with values 5, 4, 3, 7, 9 and 2
    ListNode* head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next = new ListNode(2);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the linked list in groups of K
    Solution solution;
    head = solution.reverseKGroup(head, 4);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}

