#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int data){
        val = data;
        next = nullptr;
        }
};
void insertAtEnd(ListNode*& head,int val){
    ListNode* newNode = new ListNode(val);
    if (head==nullptr)
    {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next!=nullptr)
    {
       temp = temp->next;
    }
    temp->next  = newNode;
}
void printList(ListNode* head){
    ListNode* temp = head;
    while (temp!=nullptr)
    {
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

ListNode* removeNode(ListNode* head,int n){
    ListNode* fast =head;
    ListNode* slow =head;
    for (int i = 0; i < n; i++)
    {
        fast= fast->next;
    }
    if (fast==nullptr) return head->next; //removing the first element i.e head

    while (fast->next!=nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}
int main(){
    ListNode* nums = nullptr;
    int n;
    insertAtEnd(nums,1);
    insertAtEnd(nums,2);
    insertAtEnd(nums,3);
    insertAtEnd(nums,4);
    insertAtEnd(nums,5);
    printList(nums);
    cout<<"Enter the element you want to remove: ";
    cin>>n;
    ListNode* result = removeNode(nums,n);
    cout<<"The list after removing the "<<n<<" node is :"<<endl;
    printList(result);
    return 0;
}