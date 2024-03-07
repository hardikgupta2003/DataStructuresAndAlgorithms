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

void LevelOrderTraversal(Node* root){
    if(root==NULL){
        return ;
    }

    queue<Node*> q;
    // initially push root element
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front=q.front();
        q.pop();


        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);// pushing a NULL to indicate the end of one level and start of next
            }

      }
      else{

        cout<<front->data<<" ";

        if(front->left){
        q.push(front->left);
        }
        if(front->right){
            q.push(front->right);
        }

      }
      
        }
    }






int main(){

    Node* root= createTree();
    
    cout<<"level order traversal : "<<endl;
    LevelOrderTraversal(root);

    return 0;
}