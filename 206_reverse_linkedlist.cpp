#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
Node(int value){
    data = value;
    next = nullptr;
}
};

//insertting element at the end of the linked list
void insertAtEnd(Node*& head, int value){
    Node* newNode = new Node(value);
    if (head== nullptr)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    
}
void printList(Node* head){
    Node* temp = head;
    while (temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void reverseList(Node*& head) {
    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;    // 1. Save next node
        curr->next = prev;    // 2. Reverse the link
        prev = curr;          // 3. Move prev forward
        curr = next;          // 4. Move curr forward
    }

    head = prev; // new head is the last processed node
}
int main(){
Node* nums =  nullptr;

insertAtEnd(nums,4);
insertAtEnd(nums,6);
insertAtEnd(nums,8);
printList(nums);
reverseList(nums);
printList(nums);

return 0;
}