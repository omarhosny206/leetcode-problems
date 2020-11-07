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
        priority_queue<int, vector<int>, greater<int>> nodes_minHeap;

        for (ListNode *head : lists)
        {
            while (head != nullptr)
            {
                nodes_minHeap.push(head->val);
                head = head->next;
            }
        }

        ListNode *head = new ListNode();
        ListNode *current = head;

        while (!nodes_minHeap.empty())
        {
            current->next = new ListNode(nodes_minHeap.top());
            nodes_minHeap.pop();
            current = current->next;
        }

        return head->next;
    }
};