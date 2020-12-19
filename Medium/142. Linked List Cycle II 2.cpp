// https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> nodes;

        while (head != nullptr)
        {
            if (nodes.find(head) != nodes.end())
                return head;

            nodes.insert(head);
            head = head->next;
        }

        return nullptr;
    }
};