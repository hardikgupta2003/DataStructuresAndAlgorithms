#include <bits/stdc++.h>
using namespace std;

// brute force
class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<string> ans;
        vector<int> result;

        // Fill ans with numbers in string form
        for (int i = 1; i <= n; i++)
        {
            ans.push_back(to_string(i));
        }

        // Sort lexicographically by string comparison
        sort(ans.begin(), ans.end());

        // Convert the sorted strings back to integers
        for (auto &i : ans)
        {
            result.push_back(stoi(i));
        }

        return result;
    }
};
