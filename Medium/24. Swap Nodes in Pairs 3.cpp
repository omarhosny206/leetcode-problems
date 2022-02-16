// https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *current = head;

        while (current != nullptr && current->next != nullptr)
        {
            ListNode *nextNode = current->next;
            int currentVal = current->val;

            current->val = nextNode->val;
            nextNode->val = currentVal;

            current = current->next->next;
        }

        return head;
    }
};