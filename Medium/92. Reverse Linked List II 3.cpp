// https://leetcode.com/problems/reverse-linked-list-ii/

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
    bool stop;
    ListNode *left;

public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        left = head;
        stop = false;
        recurseAndReverse(head, m, n);
        return head;
    }

    void recurseAndReverse(ListNode *right, int m, int n)
    {
        if (n == 1)
            return;

        right = right->next;

        if (m > 1)
            left = left->next;

        recurseAndReverse(right, m - 1, n - 1);

        if (left == right || right->next == left)
            stop = true;

        if (!stop)
        {
            int temp = left->val;
            left->val = right->val;
            right->val = temp;

            left = left->next;
        }
    }
};