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
    ListNode *reverseLL(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;

        while (curr != NULL)
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
        return head;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *ans = new ListNode();
        int sum = 0;
        int carry = 0;

        while (l1 || l2)
        {
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            ans->val = sum % 10;
            carry = sum / 10;

            ListNode *newNode = new ListNode(carry);
            newNode->next = ans;
            ans = newNode;
            sum = carry;
        }
        return carry == 0 ? reverseLL(ans->next) : reverseLL(ans);
    }
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode(); // Dummy node to start the result list
        ListNode *head = ans;           // Pointer to the head of the result list
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry)
        {
            int sum = carry; // Start with the carry from the previous operation

            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            ans->next = new ListNode(sum % 10); // Store the current digit in the new node
            ans = ans->next;                    // Move to the next node
        }

        return head->next; // Return the list starting from the next node after the dummy node
    }
};
