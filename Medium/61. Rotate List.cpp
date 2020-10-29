// https://leetcode.com/problems/rotate-list/

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
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        ListNode *oldTail = head;
        int n = 1;
        while (oldTail->next != nullptr)
        {
            oldTail = oldTail->next;
            n++;
        }

        k %= n;
        if (k == 0)
            return head;

        int steps = n - k;
        ListNode *newTail = oldTail;
        oldTail->next = head;

        while (steps--)
            newTail = newTail->next;

        ListNode *newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};