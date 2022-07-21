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
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;

        ListNode *first = head;
        ListNode *second = head;

        int leftPointer = left;
        int rightPointer = right;

        stack<ListNode *> nodes;

        while (--left)
            first = first->next;

        while (--right)
        {
            nodes.push(second);
            second = second->next;
        }

        if (second)
            nodes.push(second);

        while (leftPointer < rightPointer)
        {
            int val = first->val;
            first->val = nodes.top()->val;
            nodes.top()->val = val;

            first = first->next;

            nodes.pop();

            leftPointer++;
            rightPointer--;
        }

        return head;
    }
};