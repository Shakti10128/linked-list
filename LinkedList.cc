#include<bits/stdc++.h>
#include"LinkedList.h"
using namespace std;

// hello world
// cout<<"hello world";

// taking input of linked list
/*pair<Node*,Node*>*/Node* takeInput(){
    // pair<Node*,Node*> p;
    // p.first=NULL;
    // p.second = NULL;
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
    // p.second = tail;
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



// middle of linked list
int getLength(Node * head){
    int len = 0;
    while(head!=NULL){
        len++;
        head = head->next;
    }
    return len;
}
Node * findMiddle(Node * head){
    Node * temp = head;
    int len = (getLength(temp)/2);

    temp = head;
    int ans = 0;
    while(ans<len){
        temp = temp->next;
        ans++;
    }
    return temp;
}


// find cycle in linked list
bool detectLoop(Node* head){
    if(head==NULL){
        return false;
    }
    Node * temp = head;
    map<Node*,bool> vis;
    while(temp!=NULL){
        if(vis[temp]==true){
            return true;
        }
        else{
            vis[temp] = true;
            temp = temp->next;
        }
    }
    return false;
}


//  1 2 3 4 5 6 -1
int main(){
    // pair<Node*,Node*> p = takeInput();
    // Node * head = p.first;
    // Node* tail = p.second;
    Node* head = takeInput();
    Node * temp = head;
    // tail->next = head->next;

    // cout<<"Before reversing"<<endl;
    // while(temp!=NULL){
    //     cout<<temp->data<<" ";
    //     temp = temp->next;
    // }


    // Reverse LinkedList Itrative
    // cout<<endl<<"After reversing"<<endl;
    // Node *newHead = reverseLinkedList(head);
    // while(newHead!=NULL){
    //     cout<<newHead->data<<" ";
    //     newHead = newHead->next;
    // }


    // Reverse LinkedList by recursion
    // cout<<endl<<"Recursive Reverse"<<endl;
    // Node * nhead = reverseLinkedListRecursive(temp);
    // while(nhead!=NULL){
    //     cout<<nhead->data<<" ";
    //     nhead = nhead->next;
    // }

    // find middle of linked list
    // cout<<"Middle of linked list"<<endl;
    // Node * middle = findMiddle(temp);
    // cout<<middle->data<<endl;

    // detect loop in linked list
    if(detectLoop(temp)){
        cout<<"loop is present"<<endl;
    }
    else{
        cout<<"loop is not present"<<endl;
    }
}