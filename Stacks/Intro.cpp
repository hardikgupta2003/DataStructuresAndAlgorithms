#include<iostream>
#include<stack>

using namespace std;


int main(){


    //creation
    stack <int> st;

    //push
    st.push(20);
    st.push(30);
    st.push(40);
    cout<<"top of the stack :"<<st.top()<<endl;
    cout<<"size of The stack : "<<st.size()<<endl;
    // st.pop();
    // st.pop();
    // st.pop();
    // cout<<"size of The stack : "<<st.size()<<endl;

    if(st.empty()){
        cout<<"stack is empty "<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }
    int n=st.size();
    cout<<"printing stack : "<<endl;
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}