#include<bits/stdc++.h>
using namespace std;
// class
class Node{
    public:
    int data;
    Node * next;
    Node * random;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

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
// printing random pointer data
void printRandomData(Node * head){
    while(head!=NULL){
        cout<<head->random->data<<" ";
        head = head->next;
    }
}

// cloning a linked list
void insert(Node* & head, Node* & tail, int val){
    Node * temp = new Node(val);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

Node * cloneLL(Node * head){
    Node * temp = head;
    Node * cloneHead = NULL;
    Node * cloneTail = NULL;
    while(temp!=NULL){
        insert(cloneHead,cloneTail,temp->data);
        temp = temp->next;
    }
    unordered_map<Node*,Node*> mapping;
    Node * orignaNode = head;
    Node * cloneNode = cloneHead;
    while(orignaNode!=NULL){
        mapping[orignaNode] = cloneNode;
        orignaNode = orignaNode->next;
        cloneNode = cloneNode->next;
    }
    orignaNode = head;
    cloneNode = cloneHead;
    while(cloneNode!=NULL){
        cloneNode->random = mapping[orignaNode->random];
        orignaNode = orignaNode->next;
        cloneNode = cloneNode->next;
    }
    return cloneHead;
}

/*-----cloning a linked list without using any extra space----*/
Node * cloneLL2(Node * head){
    Node * temp = head;
    Node * cloneHead = NULL;
    Node * cloneTail = NULL;
    // step 1 creating a clone of orignal linked list
    while(temp!=NULL){
        insert(cloneHead,cloneTail,temp->data);
        temp = temp->next;
    }
    // step 2 cloneNode add in between orignal linked list
    Node * orignalNode = head;
    Node * cloneNode = cloneHead;
    while(orignalNode!=NULL){
        // changing oringnal node next pointer
        Node* Next = orignalNode->next;
        orignalNode->next = cloneNode;
        orignalNode = Next;
        // changing clone node next pointer
        Next = cloneNode->next;
        cloneNode->next = orignalNode;
        cloneNode = Next;

    }
    // step 3 random pointer copy
    temp = head;
    while( temp != NULL){
        if(temp->next!=NULL){
            temp->next->random = temp->random ? temp->random->next : temp ->random;
        }
        temp = temp->next->next;
    }

    // step 4 revert changes done in step 2
    orignalNode = head;
    cloneNode = cloneHead;
    while(orignalNode!=NULL){
        orignalNode->next = cloneNode->next;
        orignalNode = orignalNode->next;
        if(orignalNode!=NULL){
        cloneNode->next = orignalNode->next;
        }
        cloneNode = cloneNode->next;
    }
    // step - 5 return  the ans;
    return cloneHead;
}

//  1 2 3 4 5 6 -1
int main(){
    Node* head = takeInput();
    Node * temp = head;
    temp->random = temp->next->next;
    temp->next->random = temp->next->next->next;
    temp->next->next->next->random = temp;

    // // printing orignal random pointer data
    // cout<<"Orignal random pointer data "<<endl;
    // printRandomData(head);
    
    // // printing clone linked list random pointer data
    // cout<<endl<<"Printing clone linked list random pointer data "<<endl;
    // Node * ans = cloneLL(head);
    // printRandomData(ans);
    Node * ans2 = cloneLL2(head);
    printRandomData(ans2);
}
