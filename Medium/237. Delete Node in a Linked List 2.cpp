// https://leetcode.com/problems/delete-node-in-a-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *previous = nullptr;

        while (node->next != nullptr)
        {
            node->val = node->next->val;
            previous = node;
            node = node->next;
        }

        previous->next = nullptr;
    }
};