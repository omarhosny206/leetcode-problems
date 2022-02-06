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
private:
    struct Comparator
    {
        bool operator()(ListNode *first, ListNode *second)
        {
            return first->val > second->val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *result = new ListNode();
        ListNode *current = result;
        priority_queue<ListNode *, vector<ListNode *>, Comparator> nodes;

        for (ListNode *head : lists)
            if (head)
                nodes.push(head);

        while (nodes.size())
        {
            current->next = nodes.top();
            nodes.pop();

            current = current->next;

            if (current->next)
                nodes.push(current->next);
        }

        return result->next;
    }
};