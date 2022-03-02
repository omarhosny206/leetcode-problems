// https://leetcode.com/problems/sort-list/

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
    ListNode *sortList(ListNode *head)
    {

        if (head == nullptr)
            return nullptr;

        vector<int> vals;
        ListNode *current = head;

        while (current != nullptr)
        {
            vals.push_back(current->val);
            current = current->next;
        }

        sort(vals.begin(), vals.end());

        current = head;

        int i = 0;
        while (current != nullptr)
        {
            current->val = vals[i];
            current = current->next;
            i++;
        }

        return head;
    }
};