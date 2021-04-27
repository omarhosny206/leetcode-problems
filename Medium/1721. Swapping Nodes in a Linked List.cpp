// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *first = head;
        ListNode *second = head;
        ListNode *leftNode = nullptr;
        ListNode *rightNode = nullptr;

        while (--k)
            first = first->next;

        leftNode = first;

        while (first->next != nullptr)
        {
            first = first->next;
            second = second->next;
        }

        rightNode = second;

        int temp = leftNode->val;
        leftNode->val = rightNode->val;
        rightNode->val = temp;

        return head;
    }
};