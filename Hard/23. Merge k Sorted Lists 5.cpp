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
        int counter = lists.size();

        while (counter > 0)
        {
            counter = 0;
            int minValue = INT_MAX;
            int index = 0;

            for (int i = 0; i < lists.size(); ++i)
            {
                if (lists[i] != nullptr)
                {
                    if (minValue > lists[i]->val)
                    {
                        minValue = lists[i]->val;
                        index = i;
                    }

                    counter++;
                }
            }

            if (counter > 0)
            {
                current->next = new ListNode(minValue);
                current = current->next;
                lists[index] = lists[index]->next;
            }
        }

        return result->next;
    }
};