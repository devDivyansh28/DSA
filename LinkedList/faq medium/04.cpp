/*
Check if LL is palindrome or not

Given the head of a singly linked list representing a positive integer number. Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. Check whether the linked list values form a palindrome or not. Return true if it forms a palindrome, otherwise, return false.



A palindrome is a sequence that reads the same forward and backwards.


Example 1

Input: head -> 3 -> 7 -> 5 -> 7 -> 3

Output: true

Explanation: 37573 is a palindrome.

Example 2

Input: head -> 1 -> 1 -> 2 -> 1

Output: false

Explanation: 1121 is not a palindrome.

Example 3

Input: head -> 9 -> 9 -> 9 -> 9

Output:

true
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
private:
    /* Function to reverse a linked list
       using the iterative approach */
    ListNode* reverseLinkedList(ListNode* head) {
        // Initialize previous pointer as NULL
        ListNode* prev = NULL;
        
        // Initialize current pointer as head
        ListNode* curr = head;
        
        // Traverse the list until the end
        while (curr != NULL) {
            
            // Temporarily store the next node
            ListNode* nextNode = curr->next;
            
            // Reverse the link direction
            curr->next = prev;
            
            // Move 'prev' one step forward
            prev = curr;
            
            // Move 'curr' one step forward
            curr = nextNode;
        }
        
        // 'prev' will now point to the new head
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        /* Check if the linked list is empty
           or has only one node */
        if (head == NULL || head->next == NULL) {
            // It's a palindrome by definition
            return true; 
        }
        
        /* Initialize two pointers, slow and fast,
           to find the middle of the linked list */
        ListNode* slow = head;
        ListNode* fast = head;
        
        /* Traverse the linked list using the
           slow and fast pointer approach to
           locate the middle node */
        while (fast->next != NULL && fast->next->next != NULL) {
            
            // Move slow pointer one step
            slow = slow->next;  
            
            // Move fast pointer two steps
            fast = fast->next->next;  
        }
        
        /* Reverse the second half of the linked list
           starting from the node after the middle */
        ListNode* newHead = reverseLinkedList(slow->next);
        
        // Pointer to the first half
        ListNode* first = head;  
        
        // Pointer to the reversed second half
        ListNode* second = newHead; 
        
        /* Compare nodes from both halves
           one by one to check for palindrome */
        while (second != NULL) {
            
            // If mismatch found, not a palindrome
            if (first->val != second->val) {
                
                // Restore the original list before returning
                reverseLinkedList(newHead);  
                
                return false;
            }
            
            // Move both pointers one step ahead
            first = first->next; 
            second = second->next;  
        }
        
        /* Restore the second half of the linked list
           to its original order */
        reverseLinkedList(newHead);  
        
        // All values matched, it's a palindrome
        return true;  
    }
};


/*Function to print the linked list*/
void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    /*Create a linked list with values 1, 5, 2, 5, and 1 (15251, a palindrome)*/
    ListNode* head = new ListNode(1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(1);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Check if the linked list is a palindrome
    Solution solution;
    if (solution.isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}