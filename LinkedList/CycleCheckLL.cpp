#include<iostream>
#include<map>
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
bool hasCycle(Node *head) {
        map<Node*,bool> table;
        Node* temp=head;

        while(temp!=NULL){
            if(table[temp]==false){
                table[temp]=true;
            }
            else{
                return true;
            }
            temp=temp->Next;
        }
        return false;
    }

    int main(){

}