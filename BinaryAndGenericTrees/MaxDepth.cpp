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



//  int maxDepth(Node* root) {
//         if(root==NULL){
//             return 0;
//         }

//         int leftHeight=maxDepth(root->left);
//         int rightHeight=maxDepth(root->right);
//         int height=max(leftHeight,rightHeight)+1;

//         return height;

//     }

//  approch 2 
// using level order traversal 
int maxDepth(Node* root) {
        if(root==NULL){
        return 0;
    }

    queue<Node*> q;
    // initially push root element
    q.push(root);
    q.push(NULL);
    int count=1;

    while(!q.empty()){
        Node* front=q.front();
        q.pop();


        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);// pushing a NULL to indicate the end of one level and start of next
                count++;
            }

      }
      else{

        if(front->left){
        q.push(front->left);
        }
        if(front->right){
            q.push(front->right);
        }

      }
      
        }
        return count;
    }


int main(){

    Node* root= createTree();
    
    int ans=maxDepth(root);
    cout<<"maximum depth of binary tree : "<<ans<<endl;

    return 0;
}

// 3 9 -1 -1 20 15 -1 -1 7 -1 -1