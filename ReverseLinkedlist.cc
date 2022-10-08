#include<bits/stdc++.h>
#include"LinkedList.h"
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


// Reverse LinkedList by recursion
Node * reverseLinkedListRecursive(Node * head){
    if(head ==NULL  || head->next == NULL){
        return head;
    }
    Node * nHead = reverseLinkedListRecursive(head->next);
    head ->next->next = head;
    head->next = NULL;
    return nHead;
}


//  1 2 3 4 5 6 -1
int main(){
    Node* head = takeInput();
    Node * temp = head;

    // Reverse LinkedList Itrative
    cout<<endl<<"After reversing"<<endl;
    Node *newHead = reverseLinkedList(head);
    while(newHead!=NULL){
        cout<<newHead->data<<" ";
        newHead = newHead->next;
    }

    // Reverse LinkedList by recursion
    cout<<endl<<"Recursive Reverse"<<endl;
    Node * nhead = reverseLinkedListRecursive(temp);
    while(nhead!=NULL){
        cout<<nhead->data<<" ";
        nhead = nhead->next;
    }
}