#include <iostream>
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
    int getLen(ListNode *head)
    {
        ListNode *temp = head;
        int len = 0;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int len = getLen(head);
        int pos = len - n + 1;
        ListNode *curr = head;
        ListNode *prev = NULL;

        while (--pos)
        {
            prev = curr;
            curr = curr->next;
        }

        if (prev == NULL)
        {
            // Removing the head node
            head = curr->next;
        }
        else
        {
            prev->next = curr->next;
            curr->next = NULL;
        }
        delete curr;

        return head;
    }
};