#include<iostream>
using namespace std;


class Node{
    
    public:
    int data;
    Node* Next;
    Node* Prev;

    Node(int data){
        
        this->data=data;
        this->Next=NULL;
        this->Prev=NULL;
    }

};

int CountLL(Node * Head){
    Node* temp=Head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->Next;
    }
    return count;
}
void PrintLL(Node* Head){
    Node* temp=Head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->Next;

    }
}

void insertAtHead(Node* &Head,Node* &Tail,int data){
    if(Head==NULL){
        Node * newNode=new Node(data);
        Head=newNode;
        Tail=newNode;
    }
    //create new node
    else{
    Node * newNode=new Node(data);
    Head->Prev=newNode;
    newNode->Next=Head;
    Head=newNode;
    }
}

void insertAtTail(Node* &Head,Node* &Tail,int data){
     if(Head==NULL){
        Node * newNode=new Node(data);
        Head=newNode;
        Tail=newNode;
    }
    Node * newNode=new Node(data);
    Tail->Next=newNode;
    newNode->Prev=Tail;
    Tail=newNode;

}

void insertAtPosition(Node* &Head,Node*& Tail,int data,int pos){
    int length=CountLL(Head);
    if(pos<=1){
        insertAtHead(Head,Tail,data);
    }

    else if(pos>=(length+1)){
        insertAtTail(Head,Tail,data);
    }
    else{
        //middle
        Node* newNode=new Node(data);
        Node* prevNode=NULL;
        Node* currNode=Head;

        while(pos!=1){
            pos--;
            prevNode=currNode;
            currNode=currNode->Next;
        }

        prevNode->Next=newNode;
        newNode->Next=currNode;
        newNode->Prev=prevNode;
        currNode->Prev=newNode;
    }

}
int main(){
    
    Node* Head=NULL;
    Node* Tail=NULL;
    insertAtHead(Head,Tail,30);
    insertAtTail(Head,Tail,900);
    insertAtTail(Head,Tail,600);
    insertAtTail(Head,Tail,40);
    insertAtTail(Head,Tail,67);

    insertAtPosition(Head,Tail,1000,5);


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