//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    
    Node* findMid(Node* head){
        Node* slow=head;
        Node* fast=head->next;

        while(fast && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node* merge(Node* left, Node* right) {
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
   
    Node* mergeSort(Node* head) {
            if(head==0 || head->next==NULL){
            return head;
            } 

        //divide into halves
        
        Node* mid = findMid(head);
        Node* left = head;
        Node* right = mid->next;
        mid->next=0;

        left=mergeSort(left);
        right=mergeSort(right);

        Node* ans= merge(left,right);

        return ans;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends