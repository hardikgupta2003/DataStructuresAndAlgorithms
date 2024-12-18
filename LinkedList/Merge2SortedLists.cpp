//{ Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* left, Node* right)  
{  
      if(left==0){
            return right;
        }
        if(right==0){
            return left;
        }



        Node* ans= new Node(-1);
        Node* mptr = ans;

        while(left && right){
            if(left->data <= right->data){ // left node ka data lesser hai
                mptr->next=left;
                mptr=left;
                left=left->next;

            }
            else{
                mptr->next=right;
                mptr=right;
                right=right->next;
            }
        }

        if(left){
            mptr->next=left;
        }
        if(right){
            mptr->next=right;
        }

        return ans->next;
}  

// recursion
class Solution
{
public:
    Node *mergeTwoLists(Node *list1, Node *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        Node *result = new Node(-1);
        if (list1->data < list2->data)
        {
            result = list1;
            result->next = mergeTwoLists(list1->next, list2);
        }
        else
        {
            result = list2;
            result->next = mergeTwoLists(list1, list2->next);
        }
        return result;
    }
};