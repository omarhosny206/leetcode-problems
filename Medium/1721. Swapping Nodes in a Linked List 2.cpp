// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *left = head;
        ListNode *right = head;
        ListNode *current = head;

        int size = 0;

        while (current != nullptr)
        {
            current = current->next;
            size++;
        }

        size -= k;

        while (size--)
            right = right->next;

        while (--k)
            left = left->next;

        int temp = left->val;
        left->val = right->val;
        right->val = temp;

        return head;
    }
};