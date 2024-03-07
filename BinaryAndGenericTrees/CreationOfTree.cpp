#include<iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }

};

Node* createTree(){
    
    cout<<"enter value for node : "<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }

    Node* root= new Node(data);

    cout<<"left of node :"<<root->data<<endl;
    root->left=createTree();
    cout<<"right of node :"<<root->data<<endl;
    root->right=createTree();

    return root;
}


int main(){

    Node* root= createTree();
    cout<<root->data<<endl;

    return 0;
}