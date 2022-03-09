// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
        ListNode *result = new ListNode(0);
        ListNode *current = result;

        map<int, int> freq;

        while (head != nullptr)
        {
            freq[head->val]++;
            head = head->next;
        }

        for (auto &pair : freq)
        {
            if (pair.second == 1)
            {
                current->next = new ListNode(pair.first);
                current = current->next;
            }
        }

        return result->next;
    }
};