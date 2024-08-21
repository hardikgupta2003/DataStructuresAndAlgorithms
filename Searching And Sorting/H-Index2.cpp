#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int start = 0;
        int end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (citations[mid] == n - mid)
            {
                return n - mid;
            }
            else if (citations[mid] > n - mid)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return n - start;
    }
};

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int index = 0;
        while (index < n && n - index > citations[index])
        {
            index++;
        }
        return n - index;
    }
};