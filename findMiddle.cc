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


//  1 2 3 4 5 6 -1
int main(){
    Node* head = takeInput();
    Node * temp = head;

    // find middle of linked list
    cout<<"Middle of linked list"<<endl;
    Node * middle = findMiddle(temp);
    cout<<middle->data<<endl;
}