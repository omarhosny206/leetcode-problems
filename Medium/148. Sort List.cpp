// https://leetcode.com/problems/sort-list/

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
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *temp = slow;

        while (fast != nullptr && fast->next != nullptr)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        temp->next = nullptr;

        ListNode *left = sortList(head);
        ListNode *right = sortList(slow);
        return merge(left, right);
    }

    ListNode *merge(ListNode *left, ListNode *right)
    {
        ListNode *result = new ListNode();
        ListNode *current = result;

        while (left != nullptr && right != nullptr)
        {
            if (left->val < right->val)
            {
                current->next = left;
                left = left->next;
                current = current->next;
            }

            else
            {
                current->next = right;
                right = right->next;
                current = current->next;
            }
        }

        while (left != nullptr)
        {
            current->next = left;
            left = left->next;
            current = current->next;
        }

        while (right != nullptr)
        {
            current->next = right;
            right = right->next;
            current = current->next;
        }

        return result->next;
    }
};