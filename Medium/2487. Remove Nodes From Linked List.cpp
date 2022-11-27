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
        ListNode *result = new ListNode();

        vector<pair<int, int>> nodes;
        stack<int> values;
        unordered_set<int> positionsToRemove;

        ListNode *current = head;
        int i = 0;
        while (current != nullptr)
        {
            nodes.push_back({current->val, i});
            current = current->next;
            i++;
        }

        for (int i = nodes.size() - 1; i >= 0; --i)
        {
            while (!values.empty() && values.top() <= nodes[i].first)
                values.pop();

            if (!values.empty())
                positionsToRemove.insert(nodes[i].second);

            values.push(nodes[i].first);
        }

        current = result;

        for (int i = 0; i < nodes.size(); ++i)
        {
            if (positionsToRemove.find(nodes[i].second) == positionsToRemove.end())
            {
                current->next = new ListNode(nodes[i].first);
                current = current->next;
            }
        }

        return result->next;
    }
};