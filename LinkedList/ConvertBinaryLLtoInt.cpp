#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    int value = 0;
    int i = 0;

public:
    void solve(ListNode *head)
    {
        if (head == NULL)
            return;

        solve(head->next);
        value += head->val * pow(2, i);
        i++;
    }
    int getDecimalValue(ListNode *head)
    {
        solve(head);
        return value;
    }
};