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
    //Function for Linked List Traversal
    vector<int> LLTraversal(ListNode* head) {
        //Storing a copy of the linked list
        ListNode* temp = head;
        //To store the values 
        //Sequentially
        vector<int> ans;

        //Keep traversing
        //Until the nullptr 
        //Is not encountered
        while (temp != nullptr) {
            //Storing of the values
            ans.push_back(temp->data);
            //Storing the address of the next node
            temp = temp->next;
        }
        //Return answer 
        return ans;
    }
};

int main() {
    //Manual creation of nodes
    ListNode* y1 = new ListNode(2);
    ListNode* y2 = new ListNode(5);
    ListNode* y3 = new ListNode(8);
    ListNode* y4 = new ListNode(7);

    // Linking the nodes
    y1->next = y2;
    y2->next = y3;
    y3->next = y4;

    //Instance of
    //Solution class
    Solution sol;

    //Calling LLTraversal method 
    //To get the values
    vector<int> result = sol.LLTraversal(y1);

    //Printing the result
    cout << "Linked List Values:" << endl;
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    //Clean up 
    //Allocated memory
    delete y1;
    delete y2;
    delete y3;
    delete y4;

    return 0;
}
