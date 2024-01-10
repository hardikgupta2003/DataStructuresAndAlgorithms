#include <bits/stdc++.h>
using namespace std;


    void insertSorted(stack<int> &st,int X){
     
      
      if(st.empty() ||X>st.top()){
          st.push(X);
          return ;
      }  
      

      int temp =st.top();
      st.pop();
      
      insertSorted(st,X);
      
      st.push(temp);
      
      
      
    }
   void SortStack(stack<int> &st){
     
      
      if(st.empty()){
          return ;
      }
      

      int temp =st.top();
      st.pop();
      
      SortStack(st);


      insertSorted(st,temp);

   
      
    }
   


int main(){
   
        int N;
        cin>>N;
        stack<int> st;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            st.push(x);
        }
      
    
        SortStack(st);
        cout<<endl;

        vector<int>ans;
        while(st.size())
        {
            ans.push_back(st.top());
            st.pop();
        }
        for(int i = ans.size()-1;i>=0;i--)
        {
            cout<<ans[i]<<" ";
        }
    }

