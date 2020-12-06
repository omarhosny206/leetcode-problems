// https://leetcode.com/problems/max-number-of-k-sum-pairs/

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int operations = 0;
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] == k)
            {
                operations++;
                i++;
                j--;
            }

            else if (nums[i] + nums[j] > k)
                j--;

            else
                i++;
        }
        return operations;
    }
};