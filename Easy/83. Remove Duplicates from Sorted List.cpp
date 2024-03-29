// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
        ListNode *current = head;

        while (current != nullptr)
        {
            ListNode *temp = current->next;

            while (temp != nullptr && current->val == temp->val)
                temp = temp->next;

            current->next = temp;
            current = temp;
        }

        return head;
    }
};