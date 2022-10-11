#include<bits/stdc++.h>
#include"LinkedListClass.h"
using namespace std;

// taking input of linked list
Node* takeInput(){
    cout<<"Enter the elements of linked list for ending the linked list use -1"<<endl;
    int data;
    cin>>data;
    Node * head=NULL;
    Node * tail = NULL;
    while(data!=-1){
        Node* newHead = new Node(data);
        if(head ==NULL){
            head = newHead;
            tail = newHead;
        }
        else{
            tail->next = newHead;
            tail = newHead;
        }
        cin>>data;
    }
    return head;
}
// printin the linked list
void print(Node * head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

/*-------------------checking if linked list palindrome or not--------------------*/ 

// to checking the mid point of linked list
Node * findMid(Node * head){
    Node * slow = head;
    Node * fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
// Reverse Linked list
 Node * reverseLinkedList(Node* head){

    Node*curr = head;
    Node * prev = NULL;
    Node * forward = NULL;
    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
 }

bool isPalindrome(Node * head){
    if(head->next == NULL){
        return true;
    }
    // step 1 - find mid node
    Node * Mid  = findMid(head);
    // step 2 - reverse linked list
    Node * temp = Mid->next;
    Mid->next = reverseLinkedList(temp);
    // step 3 - compare both halfs linke list
    Node * head1 = head;
    Node * head2 = Mid->next;
    while(head2!=NULL){
        if(head1->data!=head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    // step 4 - repeat step 2 (optional)
    temp = Mid->next;
    Mid->next = reverseLinkedList(temp);
    return true;
}

//  1 2 3 4 5 6 -1
int main(){
    Node* head = takeInput();
    Node * temp = head;
    bool ans = isPalindrome(head);
    if(ans)
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;

}