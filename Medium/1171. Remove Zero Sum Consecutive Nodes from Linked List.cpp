// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *result = new ListNode();
        ListNode *current = result;

        vector<int> nums;
        unordered_map<int, int> prefixSum;
        int sum = 0;

        prefixSum[0] = 0;

        while (head != nullptr)
        {
            nums.push_back(head->val);
            head = head->next;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];

            if (prefixSum.find(sum) != prefixSum.end() && (prefixSum[sum] > prefixSum[0] || sum == 0))
                setZeroes(nums, prefixSum, accumulate(nums.begin(), nums.begin() + prefixSum[sum], 0), prefixSum[sum], i);

            prefixSum[sum] = i + 1;
        }

        for (auto &num : nums)
        {
            if (num != 0)
            {
                current->next = new ListNode(num);
                current = current->next;
            }
        }

        return result->next;
    }

    void setZeroes(vector<int> &nums, unordered_map<int, int> &prefixSum, int sum, int i, int j)
    {
        while (i <= j)
        {
            sum += nums[i];
            prefixSum[sum] = 0;
            nums[i++] = 0;
        }
    }
};