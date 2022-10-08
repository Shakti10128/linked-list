#include<bits/stdc++.h>
#include"LinkedListClass.h"
using namespace std;

// taking input of linked list
pair<Node*,Node*> takeInput(){
    pair<Node*,Node*> p;
    p.first=NULL;
    p.second = NULL;
    cout<<"Enter the elements of linked list for ending the linked list use -1"<<endl;
    int data;
    cin>>data;
    Node * head=NULL;
    Node * tail = NULL;
    while(data!=-1){
        Node* newHead = new Node(data);
        if(p.first ==NULL){
            p.first = newHead;
            tail = newHead;
        }
        else{
            tail->next = newHead;
            tail = newHead;
        }
        cin>>data;
    }
    p.second = tail;
    return p;
}

//  printing linked list
void print(Node * head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

// if there is cycle return node otherwise return node with -1 data
// we assumed that the value -1 will not be present in our linked list
Node* floydCycleInLinkedList(Node * head){
    if(head == NULL){
        return NULL;
    }
    Node * slow = head;
    Node * fast = head;
    while(slow!= NULL && fast!= NULL){
        fast = fast -> next;
        if(fast!= NULL){
            fast = fast -> next;
            slow = slow -> next;
        }
        if(slow == fast){
            return slow;
        }
    }
    Node * ans;
    ans->data =-1;
    return ans;
}


// get starting node in linked list loop
Node * getStartingNode(Node * head){
    Node * t = head;
    Node * temp = floydCycleInLinkedList(head);
    while(t!=temp){
        t = t->next;
        temp = temp->next;
    }
    return t;
}

void removeLoopInLinkedList(Node * head){
    Node * temp = head->next;
    while(temp->next!= head){
        temp = temp->next;
    }
    temp->next = NULL;
}

//  1 2 3 4 5 6 -1
int main(){
    pair<Node*,Node*> p = takeInput();
    Node * head = p.first;
    Node* tail = p.second;
    Node * temp = head;
    tail->next = head->next;

    // to detect at where slow and fast pointer meets
    floydCycleInLinkedList(temp);
    temp = head;
    
    // to detect at which position loop start
    Node * ans1 = getStartingNode(temp);
    temp = head;
    removeLoopInLinkedList(ans1);

    // after removing loop linked list traversal
    print(temp);
}