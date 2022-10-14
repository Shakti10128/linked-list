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



// add Two number in linked list

// reversing linked list
Node * reverse(Node * head){
    Node * curr = head;
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
// insertAtTail
void insertAtTail(Node * & ans, Node * & tail,int val){
    Node * temp = new Node(val);
    if(ans==NULL){
        ans = temp;
        tail = temp;
        return;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

Node * add(Node* first, Node* second){
    Node * ans = NULL;
    Node * tail = NULL;
    int carry = 0;

    while(first!=NULL || second!=NULL || carry!=0){
        int val1 = 0;
        int val2 = 0;
        if(first!=NULL){
            val1 = first->data;
        }
        if(second!=NULL){
            val2 = second->data;
        }
        int sum = carry + val1 + val2;
        int val = sum%10;
        insertAtTail(ans,tail,val);
        carry = sum/10;
        if(first!=NULL)
            first = first -> next;
        if(second!=NULL)
            second = second ->next;
    }
    return ans;
}

Node* addTwoLists(Node* first, Node* second) {
    // Write your code here.
    first = reverse(first);
    second = reverse(second);
    Node* ans = add(first,second);
    ans = reverse(ans);
    return ans;

}
//  1 2 3 4 5 6 -1
//  1 2 3 4 5 -1

int main(){
    Node * first = takeInput();
    Node * second = takeInput();
    Node * ans = addTwoLists(first,second);
    print(ans);
}