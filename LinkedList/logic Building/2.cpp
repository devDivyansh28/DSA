// Segregate odd and even nodes in Linked List

/*
Given the head of a singly linked list. Group all the nodes with odd indices followed by all the nodes with even indices and return the reordered list.



Consider the 1st node to have index 1 and so on. The relative order of the elements inside the odd and even group must remain the same as the given input.


Example 100

Input: linkedList = [1, 2, 3, 4, 5]

Output: [1, 3, 5, 2, 4]

Explanation:

The nodes with odd indices are 1, 3, 5 and the ones with even indices are 2, 4.

Example 2

Input: linkedList = [4, 3, 2, 1]

Output: [4, 2, 3, 1]

Explanation:

The nodes with odd indices are 4, 2 and the ones with even indices are 3, 1.
*/

#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

class Solution {
public:
    // Function to rearrange nodes 
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;

        /*Initialize pointers for odd 
        and even nodes and keep 
        track of the first even node*/
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* firstEven = head->next;

        // Rearranging nodes
        while (even && even->next) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }

       /* Connect the last odd 
       node to the first even node*/
        odd->next = firstEven;

        return head;
    }
};

// Function to print the linked list
void printLL(ListNode* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    // Create a linked list with given values
    vector<int> arr = {1, 3, 4, 2, 5, 6};
    ListNode* head = new ListNode(arr[0]);
    head->next = new ListNode(arr[1]);
    head->next->next = new ListNode(arr[2]);
    head->next->next->next = new ListNode(arr[3]);
    head->next->next->next->next = new ListNode(arr[4]);
    head->next->next->next->next->next = new ListNode(arr[5]);

    // Rearrange the list and print it
    Solution solution;
    head = solution.oddEvenList(head);
    printLL(head);

    return 0;
}