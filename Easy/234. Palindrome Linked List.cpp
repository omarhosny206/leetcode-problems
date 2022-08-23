// https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *firstLinkedList = head;
        ListNode *secondLinkedList = reverse(slow->next);

        while (secondLinkedList != nullptr && firstLinkedList != nullptr)
        {
            if (firstLinkedList->val != secondLinkedList->val)
                return false;

            firstLinkedList = firstLinkedList->next;
            secondLinkedList = secondLinkedList->next;
        }

        return true;
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        ListNode *current = head;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
};