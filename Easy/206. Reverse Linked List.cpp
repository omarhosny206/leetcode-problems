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
        stack<ListNode *> nodes;

        while (head != nullptr)
        {
            nodes.push(head);
            head = head->next;
        }

        ListNode *result = new ListNode();
        head = result;
        while (!nodes.empty())
        {
            ListNode *current = nodes.top();
            nodes.pop();
            head->next = new ListNode(current->val);
            head = head->next;
        }
        return result->next;
    }
};
