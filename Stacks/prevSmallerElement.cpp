// GFG help classmates 
#include <bits/stdc++.h> 
using namespace std; 

    vector<int> prevSmallerElement(vector<int> arr, int n) 
    { 
        
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            int curr = arr[i];
            
            while(!st.empty() && curr<=st.top()){
                st.pop();
            }
            ans[i]=st.top();
            st.push(curr);
            
        }
        return ans;
    } 


int main() 
{ 
	
	
		vector<int> array{2,1,4,6,3};
       vector<int> ans = prevSmallerElement(array, array.size());
		for (int i = 0; i < ans.size(); ++i)
		{
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
	
	return 0; 
}
