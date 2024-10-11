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
public:
    ListNode *swapPairs(ListNode *head)
    {
        // base case
        if (!head || !head->next)
            return head;

        // A->head;
        // B->head->next;
        // c->head->next->next;

        ListNode *temp = head->next;

        head->next = swapPairs(head->next->next);
        temp->next = head;

        return temp;
    }
};