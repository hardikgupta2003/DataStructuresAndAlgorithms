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

void  preOrderTraversal(Node * root) {
    if(root==NULL){
        return ;
    }
    // N 
    cout<< root->data<<" ";

    // L
    preOrderTraversal(root->left);
    // R 
    preOrderTraversal(root->right);


}
void  inOrderTraversal(Node * root) {
    if(root==NULL){
        return ;
    }
    // N 
    cout<< root->data<<" ";

    // L
    preOrderTraversal(root->left);
    // R 
    preOrderTraversal(root->right);


}
void  PostOrderTraversal(Node * root) {
    if(root==NULL){
        return ;
    }

    // L
    preOrderTraversal(root->left);
    // R 
    preOrderTraversal(root->right);
    // N 
    cout<< root->data<<" ";


}
int main(){

    Node* root= createTree();
    cout<<root->data<<endl;

    cout<<"preOrder Traversal : ";
    preOrderTraversal(root);
    cout<<endl;
    cout<<"inOrder Traversal : ";
    inOrderTraversal(root);
    cout<<endl;
    cout<<"PostOrder Traversal : ";
    PostOrderTraversal(root);
    cout<<endl;

    return 0;
}
//10 20 40 80 -1 -1 90 -1 -1 50 -1 -1 30 60 -1 -1 70 110 -1 -1 120 -1 -1