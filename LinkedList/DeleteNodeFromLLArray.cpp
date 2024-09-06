#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        set<int> st;
        for (auto &i : nums)
        {
            st.insert(i);
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *temp = dummy;

        while (temp->next != NULL)
        {
            if (st.find(temp->next->val) != st.end())
            {
                ListNode *curr = temp;
                ListNode *nextNode = temp->next;
                curr->next = nextNode->next;
                nextNode = NULL;
                delete nextNode;
            }
            else
            {
                temp = temp->next;
            }
        }
        ListNode *newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};