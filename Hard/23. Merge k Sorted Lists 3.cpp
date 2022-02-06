// https://leetcode.com/problems/merge-k-sorted-lists/

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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *result = new ListNode();
        ListNode *current = result;
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> nodes;

        for (ListNode *head : lists)
            if (head != nullptr)
                nodes.push({head->val, head});

        while (!nodes.empty())
        {
            current->next = nodes.top().second;
            nodes.pop();

            current = current->next;

            if (current->next != nullptr)
                nodes.push({current->next->val, current->next});
        }

        return result->next;
    }
};