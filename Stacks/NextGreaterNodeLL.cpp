
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> ll;
        while (head)
        {
            ll.push_back(head->val);
            head = head->next;
        }

        stack<int> st;
        vector<int> ans(ll.size());

        for (int i = 0; i < ll.size(); i++)
        {
            while (!st.empty() && ll[i] > ll[st.top()])
            {
                // means, ith element is the next greater of the element index present in stack
                int kids = st.top();
                st.pop();
                ans[kids] = ll[i];
            }
            st.push(i);
        }
        // st.pop();
        cout << st.top();
        return ans;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        stack<pair<int, int>> st; // pair(index,value)
        vector<int> ans;
        int i = 0;
        while (head != NULL)
        {
            ans.push_back(0);

            while (!st.empty() && head->val > st.top().second)
            {
                // head -> val is next greater value of elements present in stack
                pair<int, int> top = st.top();
                st.pop();
                ans[top.first] = head->val;
            }
            st.push({i++, head->val});

            head = head->next;
        }
        return ans;
    }
};