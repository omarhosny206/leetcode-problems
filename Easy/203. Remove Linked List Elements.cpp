// https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode *removeElements(ListNode *head, int val)
    {

        ListNode *result = new ListNode();
        ListNode *current = result;

        while (head != nullptr)
        {
            if (head->val != val)
            {
                current->next = new ListNode(head->val);
                current = current->next;
            }
            head = head->next;
        }

        return result->next;
    }
};