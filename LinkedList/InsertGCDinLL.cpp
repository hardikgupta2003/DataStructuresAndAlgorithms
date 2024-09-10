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
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *curr = head;
        ListNode *nextNode = head->next;

        while (nextNode != NULL)
        {
            int num = __gcd(curr->val, nextNode->val);
            // create a node of GCD
            ListNode *GCD = new ListNode(num);
            GCD->next = nextNode;
            curr->next = GCD;
            curr = nextNode;
            nextNode = nextNode->next;
        }
        return head;
    }
};