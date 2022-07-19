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
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        ListNode *current = head;
        ListNode *previous = nullptr;

        while (m > 1)
        {
            previous = current;
            current = current->next;
            m--;
            n--;
        }

        ListNode *leftLinkedList = previous;
        ListNode *reversedTail = current;

        ListNode *next = nullptr;
        while (n > 0)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
            n--;
        }

        if (leftLinkedList != nullptr)
            leftLinkedList->next = previous;

        else
            head = previous;

        reversedTail->next = current;

        return head;
    }
};