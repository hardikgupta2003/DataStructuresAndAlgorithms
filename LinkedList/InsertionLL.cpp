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

void insertAtHead(Node* &Head,int data){
    if(Head==NULL){
        // Create new node 
        Node* NewNode=new Node(data);
        // update head 
        Head=NewNode;
    }
    else{
     //create new node
    Node* NewNode=new Node(data);
    NewNode->Next=Head;
    // update head 
    Head=NewNode;
    }
    
}

int main(){
    Node* first=new Node(20);
    Node* Head=first;
    // Node* second=new Node(20);
    // Node* third=new Node(20);

    // first->Next=second;
    // second->Next=third;
    insertAtHead(Head,90);
    PrintLL(Head);
   


}