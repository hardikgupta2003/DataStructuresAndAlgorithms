// // gfg and hacker rank


// //{ Driver Code Starts
// //Initial Template for C++
// // C program to find n'th Node in linked list
// #include <stdio.h>
// #include <stdlib.h>
// #include<iostream>
// #include <bits/stdc++.h>
// using namespace std;

// /* Link list Node */
// struct Node {
//   int data;
//   struct Node *next;
//   Node(int x) {
//     data = x;
//     next = NULL;
//   }
// };


// /* Function to get the nth node from the last of a linked list*/
// int getNthFromLast(struct Node* head, int n);



// /* Driver program to test above function*/

// // } Driver Code Ends
// /* struct Node {
//   int data;
//   struct Node *next;
//   Node(int x) {
//     data = x;
//     next = NULL;
//   }
// };
// */

// //Function to find the data of nth node from the end of a linked list.
// class Solution{
// public:
//     int solve( Node* head,int &n,int &ans){
//         if(head==0) return -1;
        
//         solve(head->next,n,ans);
        
//         if(n == 1){
//             ans= head->data;
//         }
//         n--;
        
//         return ans;
        
//     }
//     int getNthFromLast(Node *head, int n)
//     {  
//     int ans =-1;
//     int res=solve(head,n,ans);
//     return res;
           
//     }
// };



// //{ Driver Code Starts.

// int main()
// {
//   int T,i,n,l,k;

//     cin>>T;

//     while(T--){
//     struct Node *head = NULL,  *tail = NULL;

//         cin>>n>>k;
//         int firstdata;
//         cin>>firstdata;
//         head = new Node(firstdata);
//         tail = head;
//         for(i=1;i<n;i++)
//         {
//             cin>>l;
//             tail->next = new Node(l);
//             tail = tail->next;
//         }
//     Solution obj;
//     cout<<obj.getNthFromLast(head, k)<<endl;
//     }
//     return 0;
// }
// // } Driver Code Ends


// all test case run on gfg  platform
//{ Driver Code Starts
//Initial Template for C++
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/

// } Driver Code Ends
/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
class Solution{
public:
  
    int getNthFromLast(Node *head, int n)
    {  
        
         int len=0;
        Node* temp1=head;
        while(temp1!=0){
            temp1=temp1->next;
            len++;
        }
        cout<<"len: "<<len<<endl;
        
        int pos = len-n;
        
        Node* temp = head;
        
        while(pos!=0 && temp!=0){
            temp=temp->next;
            pos--;
        }
        
        if(pos==0){
            return temp->data;
            
        }
        else{
            return -1;
        }
            
           
    }
};



//{ Driver Code Starts.

int main()
{
  int T,i,n,l,k;

   
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
    cout<<obj.getNthFromLast(head, k)<<endl;
    
    return 0;
}
// } Driver Code Ends