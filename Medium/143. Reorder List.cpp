// https://leetcode.com/problems/reorder-list/

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
    void reorderList(ListNode *head)
    {

        if (head == nullptr || head->next == nullptr)
            return;

        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *secondList = reverseList(slow->next);
        slow->next = nullptr;
        ListNode *firstList = head;

        while (secondList != nullptr)
        {
            ListNode *temp = firstList->next;
            firstList->next = new ListNode(secondList->val);
            firstList = firstList->next;
            firstList->next = temp;
            firstList = firstList->next;
            secondList = secondList->next;
        }
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *Next = nullptr;
        ListNode *current = head;

        while (current != nullptr)
        {
            Next = current->next;
            current->next = prev;
            prev = current;
            current = Next;
        }

        return prev;
    }
};