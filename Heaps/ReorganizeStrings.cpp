// leetcode meduim
// reorganize strings
// https://leetcode.com/problems/reorganize-string/description/
#include <bits/stdc++.h>
using namespace std;

class Info
{
public:
    char val;
    int count;

    Info(char val, int count)
    {
        this->val = val;
        this->count = count;
    }
};

class compare
{
public:
    bool operator()(Info a, Info b)
    {
        return a.count < b.count;
    }
};
class Solution
{
public:
    string reorganizeString(string s)
    {
        int freq[26] = {0};

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            freq[ch - 'a']++;
        }

        // push all the characters in the max heap
        priority_queue<Info, vector<Info>, compare> maxHeap;
        // push all characters into heap, where freq > 0
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                Info temp(i + 'a', freq[i]);
                maxHeap.push(temp);
            }
        }

        string ans = "";

        while (maxHeap.size() > 1)
        {
            Info first = maxHeap.top();
            maxHeap.pop();
            Info second = maxHeap.top();
            maxHeap.pop();

            ans.push_back(first.val);
            first.count--;
            ans.push_back(second.val);
            second.count--;

            if (first.count > 0)
            {
                maxHeap.push(first);
            }
            if (second.count > 0)
            {
                maxHeap.push(second);
            }
        }

        if (maxHeap.size() == 1)
        {
            Info first = maxHeap.top();
            maxHeap.pop();

            ans.push_back(first.val);
            first.count--;

            if (first.count > 0)
            {
                return "";
            }
        }
        return ans;
    }
    
    // solution with pairs 
// class Solution{
// public:
//     string reorganizeString(string s)
//     {
//         int n = s.size();
//         vector<int> freq(26, 0);
//         for (char c : s)
//         {
//             freq[c - 'a']++;
//         }
//         priority_queue<pair<int, char>> pq;
//         for (int i = 0; i < 26; i++)
//         {
//             if (freq[i] > 0)
//             {
//                 pq.push({freq[i], (char)('a' + i)});
//             }
//         }
//         string ans = "";
//         while (pq.size() > 1)
//         {
//             pair<int, char> p1 = pq.top();
//             pq.pop();
//             pair<int, char> p2 = pq.top();
//             pq.pop();
//             ans += p1.second;
//             ans += p2.second;
//             p1.first--;
//             p2.first--;
//             if (p1.first > 0)
//             {
//                 pq.push(p1);
//             }
//             if (p2.first > 0)
//             {
//                 pq.push(p2);
//             }
//         }
//         if (pq.size() == 1)
//         {
//             pair<int, char> p = pq.top();
//             if (p.first > 1)
//                 return "";
//             ans += p.second;
//         }
//         return ans;
//     }
// };
};