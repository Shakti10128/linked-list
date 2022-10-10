#include<bits/stdc++.h>
using namespace std;

// taking input of linked list

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

// taking input
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
            tail->child = newHead;
            tail = newHead;
        }
        cin>>data;
    }
    return head;
}

// pritint linked list
void print(Node * head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->child;
    }
}

// flatten linked list
Node* merge(Node* a, Node* b)
{
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    Node * result;
    if(a->data<b->data){
        result = a;
        result->child = merge(a->child,b);
    }
    else{
        result = b;
        result->child = merge(a,b->child);
    }
    result->next = NULL;
    return result;
}
Node* flattenLinkedList(Node* head) 
{ //base case
    if(head == NULL || head->next == NULL)
        return head;
    head->next = flattenLinkedList(head->next);
    Node * ans  = merge(head,head->next);
    return ans;
}




//  1 2 4 -1
//  3 5 7 -1
//  6 8 10 -1
//  9 11 12 -1
// op 1 2 3 4 5 6 7 8 9 10 11 12
int main(){
    Node* head1 = takeInput();
    Node* head2 = takeInput();
    head1->next = head2;
    Node* head3 = takeInput();
    head2->next = head3;
    Node* head4 = takeInput();
    head3->next = head4;
    head4->next = NULL;

    Node * newHead = flattenLinkedList(head1);
    print(newHead);
}
