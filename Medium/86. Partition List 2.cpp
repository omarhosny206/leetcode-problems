// https://leetcode.com/problems/partition-list/

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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *leftList = new ListNode();
        ListNode *currentLeft = leftList;
        ListNode *rightList = new ListNode();
        ListNode *currentRight = rightList;

        while (head != nullptr)
        {
            if (head->val < x)
            {
                currentLeft->next = new ListNode(head->val);
                currentLeft = currentLeft->next;
            }

            else
            {
                currentRight->next = new ListNode(head->val);
                currentRight = currentRight->next;
            }

            head = head->next;
        }

        currentLeft->next = rightList->next;
        return leftList->next;
    }
};