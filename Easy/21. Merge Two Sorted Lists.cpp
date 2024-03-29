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
        ListNode *result = new ListNode();
        ListNode *current = result;

        while (first != nullptr && second != nullptr)
        {
            if (first->val <= second->val)
            {
                current->next = new ListNode(first->val);
                first = first->next;
            }

            else
            {
                current->next = new ListNode(second->val);
                second = second->next;
            }

            current = current->next;
        }

        if (first != nullptr)
            current->next = first;

        if (second != nullptr)
            current->next = second;

        return result->next;
    }
};