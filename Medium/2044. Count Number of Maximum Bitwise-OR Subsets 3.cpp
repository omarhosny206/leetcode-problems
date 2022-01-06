// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/submissions/

class Solution
{
    int value = INT_MIN;
    vector<vector<int>> subsets;
    vector<int> currentSubset;

public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int result = 0;
        int maxOr = getOr(nums);

        dfs(nums, 0, 0);

        for (vector<int> &subset : subsets)
            if (getOr(subset) == maxOr)
                result++;

        return result;
    }

    int getOr(vector<int> &subset)
    {
        int result = 0;

        for (int &num : subset)
            result |= num;

        return result;
    }

    void dfs(vector<int> &nums, int start, int current)
    {
        subsets.push_back(currentSubset);

        for (int i = start; i < nums.size(); ++i)
        {
            currentSubset.push_back(nums[i]);
            dfs(nums, i + 1, current | nums[i]);
            currentSubset.pop_back();
        }
    }
};