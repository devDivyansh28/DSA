/*
Reverse a Doubly Linked List
You are given the head of a doubly linked list.

Reverse the list in-place and return the new head of the reversed list.

Example 1:
Input: head = [10, 20, 30]

Output:﻿ [30, 20, 10]

Example 2:
Input: head = [1, 3, 5, 7, 9]

Output: [9, 7, 5, 3, 1]
*/

/*
class ListNode {
public:
    int data;
    ListNode* prev;
    ListNode* next;

    ListNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};
*/

// class Solution {
// public:
//     ListNode* reverseDLL(ListNode* head) {
//        if(head==NULL || head->next==NULL){
//         return head;
//        }

//        ListNode* newHead = reverseDLL(head->next);

//        ListNode* front = head->next;

//        front->prev=front->next;
//        front->next=head;
//        head->next = head->prev;
//        head->prev=front;

//        return newHead;
//     }
// };