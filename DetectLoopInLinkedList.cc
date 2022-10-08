#include<bits/stdc++.h>
#include"LinkedList.h"
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
    pair<Node*,Node*> p = takeInput();
    Node * head = p.first;
    Node* tail = p.second;
    Node * temp = head;
    tail->next = head->next;

    // detect loop in linked list
    if(detectLoop(temp)){
        cout<<"loop is present"<<endl;
    }
    else{
        cout<<"loop is not present"<<endl;
    }
}
