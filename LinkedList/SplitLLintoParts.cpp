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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        // 1 - LL ki length nikal lo
        ListNode *curr = head;
        int L = 0;
        while (curr)
        {
            L++;
            curr = curr->next;
        }

        int eachBucketNodes = L / k;
        int remainderNodes = L % k;

        vector<ListNode *> result(k, NULL);

        curr = head;
        ListNode *prev = NULL;
        for (int i = 0; i < k; i++)
        {
            {
                result[i] = curr;
                for (int count = 1;
                     count <= eachBucketNodes + (remainderNodes > 0 ? 1 : 0);
                     count++)
                {
                    prev = curr;
                    curr = curr->next;
                }
                if (prev != NULL)
                {
                    prev->next = NULL;
                }
                remainderNodes--;
            }
        }
        return result;
    }
};