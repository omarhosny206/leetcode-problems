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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        return merge(list1, list2);
    }

    ListNode *merge(ListNode *first, ListNode *second)
    {
        if (first == nullptr)
            return second;

        if (second == nullptr)
            return first;

        if (first->val <= second->val)
        {
            first->next = merge(first->next, second);
            return first;
        }

        else
        {
            second->next = merge(first, second->next);
            return second;
        }
    }
};