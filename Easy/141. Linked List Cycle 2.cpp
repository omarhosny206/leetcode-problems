// https://leetcode.com/problems/linked-list-cycle/

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
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> nodes;

        while (head != nullptr)
        {
            if (nodes.find(head) != nodes.end())
                return true;

            nodes.insert(head);
            head = head->next;
        }

        return false;
    }
};