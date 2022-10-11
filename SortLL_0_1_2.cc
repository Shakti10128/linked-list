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
/* In this first we will count the occurance of zero, ones, and two 
 and then we will change the data of the linked list by using while loop*/
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

/*Suppose interviwer say to you, you are not allow to change the data of linked list.
So follow this approach in this you can make different different linked and merge them
in sorted order*/

void insertAtTail(Node* & tail,Node * curr){
    tail->next = curr;
    tail = curr;
}

Node * SortLL_0_1_2(Node * head){
    if(head == NULL){
        return head;
    }
    Node * zeroHead = new Node(-1);
    Node * zeroTail = zeroHead;
    Node * oneHead = new Node(-1);
    Node * oneTail = oneHead;
    Node * twoHead = new Node(-1);
    Node * twoTail = twoHead;

    Node * curr = head;
    // creating seperate linked list for 0,1,2
    while(curr!=NULL){
        int value = curr->data;
        if(value == 0){
            insertAtTail(zeroTail,curr);
        }
        if(value ==1){
            insertAtTail(oneTail,curr);
        }
        if(value == 2){
            insertAtTail(twoTail,curr);
        }
        curr = curr->next;
    }
    // merge 3 sublist
    if(oneHead->next!=NULL){
        zeroTail->next = oneHead->next;
    }
    else{
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next; 
    twoTail->next = NULL;

    head = zeroHead->next;
    // deleting dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
} 

//  2 1 0 2 0 1 -1
int main(){
    Node* head = takeInput();
    Node * temp = head;
    //  by changing the data we are sorting the linked list
    // Node * ans = sort_0_1_2(temp);
    // print(ans);

    // making seperate seperate linked list for diff diff value and merging them into one
    // temp = head;
    Node * ans1 = SortLL_0_1_2(temp);
    print(ans1);
}