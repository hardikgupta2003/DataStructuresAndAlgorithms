#include<iostream>
using namespace std;


class Node{
    
    public:
    int data;
    Node* Next;

    Node(int data){
        
        this->data=data;
        this->Next=NULL;
    }

};
 Node* reverseList(Node* head) {
        Node* curr=head;
        Node* prev=NULL;

        while(curr!=0){
            Node* next=curr->Next;
            curr->Next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
        return head;
    }
int main(){

}