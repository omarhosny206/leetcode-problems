// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/

class Solution
{
    int result = 0;
    int value = INT_MIN;

public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        dfs(nums, 0, 0);
        return result;
    }

    void dfs(vector<int> &nums, int start, int current)
    {
        if (current == value)
            result++;

        if (current > value)
        {
            value = current;
            result = 1;
        }

        for (int i = start; i < nums.size(); ++i)
            dfs(nums, i + 1, current | nums[i]);
    }
};