// https://leetcode.com/problems/linked-list-components/

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
    int numComponents(ListNode *head, vector<int> &G)
    {
        if (head == nullptr)
            return 0;

        unordered_set<int> record(begin(G), end(G));
        int result = 0;
        int count = 0;
        ListNode *current = head;

        while (current != nullptr)
        {
            if (record.count(current->val))
                count++;
            else
            {
                if (count != 0)
                    result++;
                count = 0;
            }
            current = current->next;
        }

        return count == 0 ? result : result + 1;
    }
};