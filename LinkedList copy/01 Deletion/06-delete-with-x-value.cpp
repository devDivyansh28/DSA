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

// Solution class
class Solution {
public:
    // To delete a node with a specific value in a linked list
    ListNode* deleteNodeWithValueX(ListNode* &head, int X) {
        // Check if list is empty
        if (head == NULL)
            return head;

        // If first node has target value, delete 
        if (head->data == X) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* temp = head;
        ListNode* prev = NULL;


        /*Traverse the list to find 
        the node with the target value*/
        while (temp != NULL) {
            if (temp->data == X) {
                // Adjust the pointers 
                prev->next = temp->next;
                // Delete node
                delete temp;
                return head;
            }
            prev = temp;
            temp = temp->next;
        }

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
    // Create a linked list from a vector
    vector<int> arr = {0, 1, 2};
    int X = 1;
    ListNode* head = new ListNode(arr[0]);
    head->next = new ListNode(arr[1]);
    head->next->next = new ListNode(arr[2]);
    
    // Print the original list
    cout << "Original List: ";
    printLL(head);
    
    // Create a Solution object 
    Solution sol;
    head = sol.deleteNodeWithValueX(head, X);

    // Print the modified linked list
    cout << "List after deleting the given value: ";
    printLL(head);

    return 0;
}