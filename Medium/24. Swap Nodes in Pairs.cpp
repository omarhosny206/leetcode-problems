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
        if (head == nullptr)
            return nullptr;

        ListNode *result = new ListNode();
        ListNode *current = result;

        current->next = head;

        while (current->next != nullptr && current->next->next != nullptr)
        {
            ListNode *first = current->next;
            ListNode *second = current->next->next;

            first->next = second->next;
            second->next = first;

            current->next = second;
            current = first;
        }

        return result->next;
    }
};