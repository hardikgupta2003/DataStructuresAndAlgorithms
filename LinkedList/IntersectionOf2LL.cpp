#include <bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;
        unordered_map<ListNode *, bool> mp;
        while (headA != NULL)
        {
            mp[headA] = true;
            headA = headA->next;
        }
        while (headB != NULL)
        {
            if (mp[headB] == true)
            {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};