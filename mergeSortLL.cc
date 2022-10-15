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

void print(Node * head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

/*---------------------------mergeSort Two linked list---------------------------*/

// finding mid point
Node * findMid(Node * head){
    Node * slow = head;
    Node * fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// merging two sorted linked list
Node * merge(Node *head1,Node* head2){
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
Node * mergeSortLL(Node * head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    // finding mid and dividing linked list into two parts left and right
    Node * mid = findMid(head);
    Node * left = head;
    Node * right = mid->next;
    mid->next = NULL;

    // Sorting linked list
    left = mergeSortLL(left);
    right = mergeSortLL(right);
    
    // merging two sorted linked list and returning the answer
    Node * ans = merge(left,right);
    return ans;
}

//  1 5 9 2 6 3 8 4 7 -1
int main(){
    Node* head = takeInput();
    Node * temp = mergeSortLL(head);
    print(temp);
}