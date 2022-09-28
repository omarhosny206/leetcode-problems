// https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int size = 0;
        ListNode *current = head;

        while (current != nullptr)
        {
            current = current->next;
            size++;
        }

        size -= n;
        current = head;

        if (size == 0)
            return head->next;

        while (--size)
            current = current->next;

        current->next = current->next->next;
        return head;
    }
};