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
// printing the linked list
void print(Node * head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}



Node * mergeTwoSortedLL(Node *head1,Node* head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    Node * temp = NULL;
    Node * tail = NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->data < head2->data){
            if(temp == NULL){
                temp = head1;
                tail = head1;
            }
            else{
                tail->next = head1;
                tail = tail->next;
            }
            head1 = head1->next;
        }
        else{
            if(temp == NULL){
                temp = head2;
                tail = head2;
            }
            else{
                tail->next = head2;
                tail = tail->next;
            }
            head2 = head2->next;
        }
    }
    while(head1!=NULL){
        tail->next = head1;
        tail = tail->next;
        head1 = head1->next;
    }
    while(head2!=NULL){
        tail->next = head2;
        tail = tail->next;
        head2 = head2->next;
    }
    return temp;
}
    

//  1 3 5 7 9 -1
//  2 4 6 8 -1
int main(){
    Node* head1 = takeInput();
    Node* head2 = takeInput();
    Node * temp1 = head1;
    Node * temp2 = head2;
    Node * newHead = mergeTwoSortedLL(temp1,temp2);
    print(newHead);
}