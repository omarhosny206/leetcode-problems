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
        if (head == nullptr)
            return true;

        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *secondLinkedList = reverseList(slow->next);
        ListNode *firstLinkedList = head;

        while (secondLinkedList != nullptr && firstLinkedList != nullptr)
        {
            if (firstLinkedList->val != secondLinkedList->val)
                return false;
            firstLinkedList = firstLinkedList->next;
            secondLinkedList = secondLinkedList->next;
        }
        return true;
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
