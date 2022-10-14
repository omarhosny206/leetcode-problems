// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

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
    ListNode *deleteMiddle(ListNode *head)
    {
        int size = 0;
        ListNode *current = head;

        while (current != nullptr)
        {
            size++;
            current = current->next;
        }

        if (size == 1)
            return nullptr;

        size /= 2;
        size--;

        current = head;

        while (size--)
        {
            current = current->next;
        }

        current->next = current->next->next;
        return head;
    }
};