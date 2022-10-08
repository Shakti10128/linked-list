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

// if there is cycle return node otherwise return node with -1 data
// we assumed that the value -1 will not be present in our linked list
bool floydCycleInLinkedList(Node * head){
    if(head == NULL){
        return false;
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
            return true;
        }
    }
    return false;
}

//  1 2 3 4 5 6 -1
int main(){
    pair<Node*,Node*> p = takeInput();
    Node * head = p.first;
    Node* tail = p.second;
    Node * temp = head;
    tail->next = head->next;

    
    // floydCycleInLinkedList
    bool ans = floydCycleInLinkedList(temp);
    if(ans){
        cout<<"cycle is present"<<endl;
    }
    else{
        cout<<"cycle is not present"<<endl;
    }

}