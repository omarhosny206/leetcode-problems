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
        ListNode *result = new ListNode(0);
        ListNode *current = result;

        current->next = head;

        while (head != nullptr)
        {
            if (head->next != nullptr && head->val == head->next->val)
            {
                while (head->next != nullptr && head->val == head->next->val)
                    head = head->next;

                current->next = head->next;
            }

            else
                current = current->next;

            head = head->next;
        }

        return result->next;
    }
};