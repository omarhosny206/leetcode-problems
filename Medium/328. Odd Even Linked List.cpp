// https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr)
            return head;

        ListNode *odd = head;
        ListNode *previous = nullptr;

        ListNode *evenHead = new ListNode();
        ListNode *even = evenHead;

        while (odd != nullptr && odd->next != nullptr)
        {
            previous = odd;

            even->next = odd->next;
            even = even->next;

            odd->next = even->next;
            odd = odd->next;
        }

        even->next = nullptr;

        if (odd != nullptr)
            odd->next = evenHead->next;

        else
            previous->next = evenHead->next;

        return head;
    }
};