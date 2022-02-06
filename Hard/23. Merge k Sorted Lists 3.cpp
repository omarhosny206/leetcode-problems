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
        vector<int> nodes;

        for (ListNode *head : lists)
        {
            while (head != nullptr)
            {
                nodes.push_back(head->val);
                head = head->next;
            }
        }

        sort(nodes.begin(), nodes.end());

        for (int i = 0; i < nodes.size(); ++i)
        {
            current->next = new ListNode(nodes[i]);
            current = current->next;
        }

        return result->next;
    }
};