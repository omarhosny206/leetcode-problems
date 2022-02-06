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
        priority_queue<int, vector<int>, greater<int>> nodes;

        for (ListNode *head : lists)
        {
            while (head != nullptr)
            {
                nodes.push(head->val);
                head = head->next;
            }
        }

        while (!nodes.empty())
        {
            current->next = new ListNode(nodes.top());
            nodes.pop();
            current = current->next;
        }

        return result->next;
    }
};