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


// sorting linked list 0_1_2
Node * sort_0_1_2(Node * head){
    if(head == NULL){
        return head;
    }
    Node * temp = head;
    int countzero = 0;
    int countone = 0;
    int counttwo = 0;
    while(temp!=NULL){
        if(temp->data == 0){
            countzero++;
        }
        else if(temp->data == 1){
            countone++;
        }
        else{
            counttwo++;
        }
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){
        if(countzero!=0){
            temp->data = 0;
            countzero--;
        }
        else if(countone!=0){
            temp->data = 1;
            countone--;
        }
        else if(counttwo!=0){
            temp->data = 2;
            counttwo--;
        }
        temp = temp->next;
    }
    return head;

}

//  2 1 0 2 0 1 -1
int main(){
    Node* head = takeInput();
    Node * temp = head;
    Node * ans = sort_0_1_2(temp);
    print(ans);
}