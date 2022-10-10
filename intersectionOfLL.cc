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

// finding intersection in linked list

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node * curr = firstHead;
    map<Node*,bool> vis;
    if(firstHead==NULL || secondHead==NULL){
        return -1;
    }
    while(curr!=NULL){
        vis[curr]=true;
        curr = curr->next;
    }
    curr = secondHead;
    while(curr!=NULL){
        if(vis[curr]==true){
            return curr->data;
        }
        else{
            curr = curr->next;
        }
    }
    return -1;

}
// pritint linked list
void print(Node * head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

//  1 2 3 4 5 6 -1
//  7 8 9 -1
int main(){
    Node* head1 = takeInput();
    Node * temp1 = head1;
    Node* head2 = takeInput();
    head2->next->next->next =head1->next->next->next;
    Node * temp2 = head2;

    int ans = findIntersection(temp1,temp2);
    cout<<endl<<"intersection of two linked list "<<ans<<endl;
}

