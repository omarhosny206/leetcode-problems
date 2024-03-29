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
        ListNode *leftDummy = new ListNode(0);
        ListNode *rightDummy = new ListNode(0);
        ListNode *currentLeft = leftDummy;
        ListNode *currentRight = rightDummy;

        while (head != nullptr)
        {
            if (head->val < x)
            {
                currentLeft->next = head;
                currentLeft = currentLeft->next;
            }

            else
            {
                currentRight->next = head;
                currentRight = currentRight->next;
            }

            head = head->next;
        }

        currentLeft->next = rightDummy->next;
        currentRight->next = nullptr;

        return leftDummy->next;
    }
};