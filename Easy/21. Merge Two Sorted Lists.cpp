// https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *empty;
        if (l1 == nullptr && l2 == nullptr)
            return empty;

        ListNode *current = new ListNode();
        ListNode *answer = current;

        while (l1 != nullptr && l2 != nullptr)
        {

            if (l1->val < l2->val)
            {
                current->next = new ListNode(l1->val);
                l1 = l1->next;
            }

            else
            {
                current->next = new ListNode(l2->val);
                l2 = l2->next;
            }

            current = current->next;
        }

        if (l1)
            current->next = l1;
        if (l2)
            current->next = l2;

        return answer->next;
    }
};