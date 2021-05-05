// https://leetcode.com/problems/next-greater-node-in-linked-list/

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
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> result;
        vector<int> data;
        stack<int> nums;

        while (head != nullptr)
        {
            data.push_back(head->val);
            head = head->next;
        }

        for (int i = data.size() - 1; i >= 0; --i)
        {
            while (!nums.empty() && nums.top() <= data[i])
                nums.pop();

            int value = nums.empty() ? 0 : nums.top();
            result.push_back(value);

            nums.push(data[i]);
        }

        Reverse(result);
        return result;
    }

    void Reverse(vector<int> &data)
    {
        int i = 0;
        int j = data.size() - 1;

        while (i < j)
        {
            int temp = data[i];
            data[i++] = data[j];
            data[j--] = temp;
        }
    }
};