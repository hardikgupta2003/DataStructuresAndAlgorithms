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


void PrintLL(Node* Head){
    Node* temp=Head;
    while(Head!=NULL){
        cout<<temp->data<<"->";
        temp=temp->Next;

    }
}
int main(){
    Node* first=new Node(20);
    Node* Head=first;
    Node* second=new Node(20);
    Node* third=new Node(20);

    first->Next=second;
    second->Next=third;
    PrintLL(Head);

}