// https://leetcode.com/problems/reverse-linked-list/

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
    ListNode *reverseList(ListNode *head)
    {
        return reverseListRecursively(head);
    }

    ListNode *reverseListRecursively(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *current = reverseListRecursively(head->next);
        head->next->next = head;
        head->next = nullptr;
        return current;
    }
};