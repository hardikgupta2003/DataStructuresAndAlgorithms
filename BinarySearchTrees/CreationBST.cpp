#include <iostream>
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
Node* insertIntoBST(Node* root,int data){
    // its the first node 
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    // its not the first Node
    if(data> root->data){
       root->right= insertIntoBST(root->right,data);
    }
    else{
        root->left = insertIntoBST ( root->left,data);
    }
}
Node* createBST(Node* &root){
    cout<<"enter the value : "<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }

   while(data!=-1){
    root= insertIntoBST(root,data);
    cin>>data;
   }
}

int main(){

    Node*  root = NULL;
     createBST(root);
     
}