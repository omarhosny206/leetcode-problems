// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        set<int> nodes;
        ListNode *current = head;
        while (current != nullptr)
        {
            nodes.insert(current->val);
            current = current->next;
        }

        ListNode *answer = new ListNode();
        current = answer;
        for (int val : nodes)
        {
            current->next = new ListNode(val);
            current = current->next;
        }

        return answer->next;
    }
};