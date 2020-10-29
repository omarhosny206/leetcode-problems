// https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode *removeElements(ListNode *head, int val)
    {

        queue<ListNode *> nodes;

        while (head != nullptr)
        {
            if (head->val != val)
                nodes.push(head);
            head = head->next;
        }

        ListNode *result = new ListNode();
        ListNode *current = result;

        while (!nodes.empty())
        {
            current->next = new ListNode(nodes.front()->val);
            current = current->next;
            nodes.pop();
        }

        return result->next;
    }
};