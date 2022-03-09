// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *result = new ListNode();
        ListNode *current = result;

        ListNode *right = head;

        while (right != nullptr)
        {
            ListNode *left = right;

            while (right->next != nullptr && right->val == right->next->val)
                right = right->next;

            if (left == right)
            {
                current->next = left;
                current = current->next;
            }

            else
                current->next = right->next;

            right = right->next;
        }

        return result->next;
    }
};