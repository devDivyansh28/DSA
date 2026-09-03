#include<bits/stdc++.h>
using namespace std;

// struct Node {
//     public:
//     int data;
//     Node* next;

//     public: 
//     Node(int data1 , Node* next){
//         data =  data1;
//         next = next;
//     }
   
//     Node(int data1 ){
//         data =  data1;
//         next = nullptr;
//     }
// };

// As in struct it does not provide oop features like encapsulation and inheritance, we will use class instead of struct.

class Node {
    public:
    int data;
    Node* next;

    public: 
    Node(int data1 , Node* next){
        data =  data1;
        next = next;
    }
   
    Node(int data1 ){
        data =  data1;
        next = nullptr;
    }
};

Node* arrToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 0 ; i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

int main() {
    vector<int> arr = {2 , 5 , 8 , 7};


    Node x = Node(arr[2] , nullptr);
    Node* y = &x;
    Node* z = new Node(arr[3] , nullptr);
    cout << x.data << endl;

    Node* head = arrToLL(arr);
    cout<< head->data;

}