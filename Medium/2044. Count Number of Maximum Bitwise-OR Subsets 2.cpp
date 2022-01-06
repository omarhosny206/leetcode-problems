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
        if (start == nums.size())
        {
            if (current == value)
                result++;

            if (current > value)
            {
                value = current;
                result = 1;
            }

            return;
        }

        dfs(nums, start + 1, current | nums[start]);
        dfs(nums, start + 1, current);
    }
};