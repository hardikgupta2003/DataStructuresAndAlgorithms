//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
     Node* reverseList(Node* head) {
        Node* curr=head;
        Node* prev=NULL;

        while(curr!=0){
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
        return head;
    }
    Node* addOne(Node *head) 
    {   // step 1 reverse
        head=reverseList(head);
        
        
        //step 2 add (1)
        int carry=1;
        Node * temp=head;
        Node * prev=NULL;
        
        
        while(temp!=NULL){
            int totalSum=temp->data+carry;
            int digit=totalSum%10;
            carry=totalSum/10;
            prev=temp;
            temp->data=digit;
            temp=temp->next;
            
            if(carry==0){
                break;
                
            }
        }
        
        if(carry!=0){
            
                Node* newNode=new Node(carry);
                prev->next=newNode;
            
            
        }
        
        head=reverseList(head);
        return head;
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends