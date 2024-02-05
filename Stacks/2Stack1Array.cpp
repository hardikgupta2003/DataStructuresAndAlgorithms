//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class twoStacks
{
    public:
        int *arr;
        int size;
        int top1;
        int top2;
    twoStacks(int n)
    {
        arr=new int[size];
        this->size=n;
        top1=-1;
        top2=size;
        
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        if(top2-top1==1){
            cout<<"overflow at 1"<<endl;
        }
        else{
             top1++;
        arr[top1]=x;
        }
       
        
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
        
        if(top2-top1==1){
            cout<<"overflow at 2"<<endl;
        }
        else{
           top2--;
       arr[top2]=x; 
        }
       
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(top1==-1){
            return -1;
        }
        else{
            arr[top1]=0;
        top1--;
        }
        
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
        if(top2==size){
            cout<<"underflow"<<endl;
        }
        else{
           arr[top2]=0;
            top2++; 
        }
       
    }

    void print(){
        cout<<endl;
        cout<< "top1: "<<top1<<endl;
        cout<< "top2: "<<top2<<endl;
        cout<<"printing stack: ";
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        
        

    }
};



//{ Driver Code Starts.

int main()
{
    twoStacks st(6);
    st.print();

    st.push2(10);
    st.push2(10);
    st.push2(10);
    st.print();
    st.push1(20);
    st.push1(20);
    st.push1(20);
    st.print();
    st.push2(90);
    st.print();
    
    
        cout<<endl;
    
}

// } Driver Code Ends