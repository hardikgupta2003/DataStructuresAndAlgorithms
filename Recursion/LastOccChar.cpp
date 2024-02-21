// //gfg

// //{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// class Solution{
//     public:
//     void solve(string &s,char p,int index,int &ans){
//         //base case
//         if(index>=s.length()){
//             return ;
//         }
        
//         if(s[index]==p){
//             ans=index;
//         }
//         solve(s,p,index+1,ans);
     
//     }
//     // int LastIndex(string s, char p){
//     //     int index=0;
//     //     int ans = -1;
//     //     solve(s,p,index,ans);
//     //     return ans;
//     // }
    

//     //without recursion
//     int LastIndex(string s, char p){
//         for(int i=s.length()-1;i>0;i--){
//             if(s[i]==p){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

// //{ Driver Code Starts.

// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         string s;
//         cin >> s;
//         char p;
//         cin >> p;
//         Solution ob;
//         cout << ob.LastIndex(s, p) << endl;
//     }
//     return 0;
// }


// // } Driver Code Ends

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int solve(string &s,char p,int index,int &ans){
        //base case
        if(index>=s.length()){
            return -1;
        }
        
        if(s[index]==p){
            return index;
        }
        
     solve(s,p,index-1,ans);
    }
    int LastIndex(string s, char p){
        int index=s.length()-1;
        int ans = -1;
        solve(s,p,index,ans);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        char p;
        cin >> p;
        Solution ob;
        cout << ob.LastIndex(s, p) << endl;
    }
    return 0;
}


// } Driver Code Ends