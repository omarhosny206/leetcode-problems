// https://leetcode.com/problems/remove-nodes-from-linked-list/

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
    ListNode *removeNodes(ListNode *head)
    {
        ListNode *current = head;
        vector<ListNode *> nodes;
        stack<ListNode *> values;

        while (current != nullptr)
        {
            nodes.push_back(current);
            current = current->next;
        }

        values.push(nodes[nodes.size() - 1]);

        for (int i = nodes.size() - 2; i >= 0; --i)
        {
            if (!values.empty() && nodes[i]->val >= values.top()->val)
            {
                nodes[i]->next = values.top();
                values.pop();
                values.push(nodes[i]);
            }
        }

        return values.top();
    }
};