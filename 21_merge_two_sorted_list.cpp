#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data){
        val = data;
        next = nullptr;
    }
};
void insertAtEnd(ListNode*& head, int val){
    ListNode* newNode = new ListNode(val);
    if(head==nullptr)
    {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next !=nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void printList(ListNode* head){
    ListNode* temp = head;
    while (temp != nullptr)
    {
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

}
ListNode* mergeList(ListNode *nums1 , ListNode * nums2){
    ListNode* mergedHead = nullptr;
    ListNode* tail = nullptr;
    while (nums1 &&nums2){
        ListNode* node = (nums1->val<nums2->val)?nums1:nums2;
        if (node == nums1)      
        {
            nums1 = nums1->next;
        }
        else{
            nums2 = nums2->next;

        }
        if (!mergedHead)
        {
            mergedHead = node;
            tail = node;
        }
        else{
            tail->next = node;
            tail = node;
        }
        

    }
        if(nums1) tail->next = nums1;
        if(nums2) tail->next = nums2;
   return mergedHead;
}
void printMergedList(ListNode* mergedHead){
    ListNode* temp = mergedHead;
while (temp!= nullptr)
{
    cout<<temp->val<<"->";
    temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    ListNode* nums1 = nullptr;
    insertAtEnd(nums1,2);
    insertAtEnd(nums1,4);
    insertAtEnd(nums1,6);
    printList(nums1);
    ListNode* nums2 = nullptr;
    insertAtEnd(nums2,1);
    insertAtEnd(nums2,3);
    insertAtEnd(nums2,5);
    printList(nums2);
    ListNode* merge = mergeList(nums1,nums2);
    printMergedList(merge);
    return 0;
}