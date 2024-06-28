//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

// } Driver Code Ends
// User function Template for C++
class Info
{
public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int a, int b, int c)
    {
        this->data = a;
        this->rowIndex = b;
        this->colIndex = c;
    }
};

class compare
{
public:
    bool operator()(Info *a, Info *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        vector<int> ans;
        priority_queue<Info *, vector<Info *>, compare> pq;
        // 1 step : process firsk k elements
        for (int row = 0; row < k; row++)
        {
            int element = arr[row][0];
            Info *temp = new Info(element, row, 0);
            pq.push(temp);
        }

        while (!pq.empty())
        {
            Info *temp = pq.top();
            pq.pop();
            int topData = temp->data;
            int topRow = temp->rowIndex;
            int topCol = temp->colIndex;

            // store in ans vector
            ans.push_back(topData);

            // next element for the same row, jisme se pop kia h just abhi
            // use insert bhi toh karna hai
            if (topCol + 1 < arr[topRow].size())
            {
                // iska matlab row me or element abhi present hai
                Info *newInfo = new Info(arr[topRow][topCol + 1], topRow, topCol + 1);
                pq.push(newInfo);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        vector<vector<int>> arr(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends