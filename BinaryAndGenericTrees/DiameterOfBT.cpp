#include<iostream>
#include<queue>
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


int maxDepth(Node* root) {
        if(root==NULL){
            return 0;
        }

        int leftHeight=maxDepth(root->left);
        int rightHeight=maxDepth(root->right);
        int height=max(leftHeight,rightHeight)+1;

        return height;

    }


    int diameterOfBinaryTree(Node* root) {

        if(root==NULL){
            return 0;
        }

        cout<<"data of root  is: "<<root->data<<endl;
        int op1=diameterOfBinaryTree(root->left);
         cout<<"op1: "<<op1<<endl;


        cout<<"data of root  is: "<<root->data<<endl;
        int op2=diameterOfBinaryTree(root->right);
         cout<<"op2: "<<op2<<endl;


        cout<<"data of root  is: "<<root->data<<endl;
        int op3=maxDepth(root->left)+maxDepth(root->right);
         cout<<"op3: "<<op3<<endl;


        int diameter=max(op1,max(op2,op3));
        cout<<"diameter :"<<diameter<<endl;
        return diameter;
        
    }

    int main(){

    Node* root= createTree();
    
    int ans=diameterOfBinaryTree(root);
    cout<<"diameter of binary tree : "<<ans<<endl;

    return 0;
}

// 3 9 -1 -1 20 15 -1 -1 7 -1 -1
// 1 2 4 -1 -1 5 -1 -1 3 -1 -1