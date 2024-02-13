// leetcode hard 84 
#include <bits/stdc++.h> 
using namespace std; 
    vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            // ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            // ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }


    int largestRectangleArea(vector<int>& heights) {

        vector<int> next = nextSmallerElement(heights, heights.size());
        vector<int> prev = prevSmallerElement(heights, heights.size());

        int maxArea = INT_MIN;
        for (int i = 0; i < heights.size(); i++) {

            int length = heights[i];
            if (next[i] == -1) {

                next[i] = heights.size();
            }
            int breadth = next[i] - prev[i] - 1;
            int area = length * breadth;

            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
int main() 
{ 
	
	
		vector<int> array{2,1,5,6,2,3};
       int ans = largestRectangleArea(array);
		
			cout<<ans<<" ";
		
		cout<<"\n";
	
	return 0; 
}