//key pair or two sum 

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
        //1) bruteforce method but TLE 
	    // for(int i=0;i<n;i++){
	    //     for(int j=i+1;j<n;j++){
	    //         if(arr[i]+arr[j]==x){
	    //             return true;
	    //         }
	           
	    //     }
	    // }
	    // return false;

        // 2) two pointer approach
         sort(arr,arr+n);
	    int s=0;
	    int e=n-1;
	    int cSum=0;
	    while(s<e){
	        cSum=arr[s]+arr[e];
	        if(cSum==x){
	            return true;
	        }
	        else if(cSum>x){
	            e--;
	        }
	        else{
	            s++;
	        }
	    }
	    return false;

	}
};

//{ Driver Code Starts.

int main() {
   
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    
    return 0;
}

// } Driver Code Ends