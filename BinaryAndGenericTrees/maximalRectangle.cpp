class Solution
{
public:
    // Finds index of next smaller element for each bar (to the right)
    vector<int> nextSmallerElement(vector<int> arr, int n)
    {
        stack<int> s;
        s.push(-1); // sentinel to handle empty stack
        vector<int> ans(n);

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];

            // Pop until we find a smaller element
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }

            // Top of stack is the next smaller element index
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    // Finds index of previous smaller element for each bar (to the left)
    vector<int> prevSmallerElement(vector<int> arr, int n)
    {
        stack<int> s;
        s.push(-1); // sentinel
        vector<int> ans(n);

        // Traverse from left to right
        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];

            // Pop until we find a smaller element
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }

            // Top of stack is the previous smaller element index
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    // Calculates largest rectangle area in a histogram
    int largestRectangleArea(vector<int> &heights)
    {

        // Indices of next and previous smaller bars
        vector<int> next = nextSmallerElement(heights, heights.size());
        vector<int> prev = prevSmallerElement(heights, heights.size());

        int maxArea = INT_MIN;

        // Compute area for each bar as the smallest bar
        for (int i = 0; i < heights.size(); i++)
        {

            int height = heights[i];

            // If no smaller element on right, extend till end
            if (next[i] == -1)
            {
                next[i] = heights.size();
            }

            // Width of rectangle where heights[i] is minimum
            int width = next[i] - prev[i] - 1;

            int area = height * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

    // Main function for Maximal Rectangle in Binary Matrix
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxArea = INT_MIN;

        // height[j] represents number of consecutive 1s above current row in column j
        vector<int> height(m, 0);

        // Treat each row as the base of a histogram
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                // Update histogram height column-wise
                if (matrix[i][j] == '0')
                {
                    height[j] = 0;
                }
                else
                {
                    height[j]++;
                }
            }

            // Calculate max rectangle for current histogram
            maxArea = max(maxArea, largestRectangleArea(height));
        }

        return maxArea;
    }
};
