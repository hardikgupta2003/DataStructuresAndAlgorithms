// leetcode hard 
// gfg medium

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    int getLen(struct node * head){
        int count=0;
        struct node* temp=head;

        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    struct node *reverseIt (struct node *head, int k)
    { 
        int len=getLen(head);
        if (head == NULL ) {
            return head;
        }
        if(head->next==NULL){
            return head;
        }
        if(len<k){
            return head;
        }
        struct node* prev = NULL;
        struct node* curr = head;
        struct node* nextNode = curr->next;
        int pos = 1;

        while (pos <= k) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            pos++;
            len--;
            
        }

        struct node* recAns = NULL;
        if (nextNode != NULL) {
            if(len<k){
            recAns = reverseIt(nextNode, len);

            head->next = recAns;
        }
        else{
            recAns = reverseIt(nextNode, k);

            head->next = recAns;
        }
        }
        return prev;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverseIt(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends