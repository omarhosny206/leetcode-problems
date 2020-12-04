// https://leetcode.com/problems/merge-in-between-linked-lists/

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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        int i = 0;
        ListNode *current = list1;
        while (i < a - 1)
        {
            current = current->next;
            i++;
        }

        ListNode *right = new ListNode();
        right->next = current;
        while (i < b + 1)
        {
            right = right->next;
            i++;
        }

        current->next = list2;

        while (current->next != nullptr)
            current = current->next;

        current->next = right->next;

        return list1;
    }
};