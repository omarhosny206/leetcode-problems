// https://leetcode.com/problems/insertion-sort-list/

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
    ListNode *insertionSortList(ListNode *head)
    {

        vector<int> nodes;
        ListNode *current = head;
        while (current != nullptr)
        {
            nodes.push_back(current->val);
            current = current->next;
        }

        sort(nodes.begin(), nodes.end());
        current = head;

        while (!nodes.empty())
        {
            current->val = nodes.front();
            nodes.erase(nodes.begin());
            current = current->next;
        }

        return head;
    }
};
