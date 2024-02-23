//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		   int freq[26]={0};
		   string ans="";
		   queue<char> q;
		   
		   for(int i=0;i<A.length();i++){
		       char ch = A[i];
		       freq[ch-'a']++;
		       q.push(ch);
		       
		       //answer find karo
		       while(!q.empty()){
		           char frontCh = q.front();
		           if(freq[frontCh - 'a']>1){ 
		               //ek se jyada hai to answer nhi ho sakta 
		               q.pop();
		           }
		           else{
		               // ye unique hai kyuki iska count 1 hi hai
		               ans.push_back(frontCh);
		               break;
		           }
		           
		       }
		       if(q.empty()){
		           //agr saare char q ke khtm hogye 
		           ans.push_back('#');
		       }
		       
		   }
		   return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends