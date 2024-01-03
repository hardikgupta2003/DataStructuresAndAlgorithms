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

void insertAtHead(Node* &Head,Node* &Tail,int data){
    if(Head==NULL){
        // Create new node 
        Node* NewNode=new Node(data);
        // update head 
        Head=NewNode;
        Tail=NewNode;
    }
    else{
     //create new node
    Node* NewNode=new Node(data);
    NewNode->Next=Head;
    // update head 
    Head=NewNode;
    }
    
}
void insertAtTail(Node* &Head,Node* &Tail,int data){
    if(Tail==NULL){
        // Create new node 
        Node* NewNode=new Node(data);
        // update head 
        Tail=NewNode;
        Head=NewNode;
    }
    else{
     //create new node
    Node* NewNode=new Node(data);
    Tail->Next=NewNode;
    // update head 
    Tail=NewNode;
    }
    
}
int CountLL(Node * Head){
    Node* temp=Head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->Next;
    }
    return count;

}
void insertAtPosition(Node* &Head,Node* &Tail,int data,int pos){
    int length=CountLL(Head);

    if(pos<=1){
        insertAtHead(Head,Tail,data);

    }
    else if(pos>=length+1){
        insertAtTail(Head,Tail,data);

    }
    else{
        //create new node 
        Node* NewNode=new Node(data);
        Node* prev=NULL;
        Node* curr=Head;

        while(pos!=1){
            prev=curr;
            curr=curr->Next;
            pos--;
        }
        prev->Next=NewNode;
        NewNode->Next=curr;
    }
    
}

int main(){
    // MORE GENERIC WAY OF CREATING LINKEDLIST
    Node* Head=NULL;
    Node* Tail=NULL;

    insertAtHead(Head,Tail,30);
    insertAtHead(Head,Tail,20);
    insertAtHead(Head,Tail,10);

    insertAtTail(Head,Tail,40);
    insertAtPosition(Head,Tail,900,2);



    PrintLL(Head);




    // CLASSICAL WAY OF CREATING LINKEDLIST
    // Node* first=new Node(20);
    // Node* Head=first;
    // Node* second=new Node(20);
    // Node* third=new Node(20);
    // Node* Tail=third;
    
    // first->Next=second;
    // second->Next=third;
    // insertAtHead(Head,90);
    // insertAtTail(Tail,90);
    
   


}