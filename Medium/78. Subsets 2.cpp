// https://leetcode.com/problems/subsets/

class Solution
{
    vector<vector<int>> result;
    vector<int> currentSubset;

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        dfs(nums, 0);
        return result;
    }

    void dfs(vector<int> &nums, int start)
    {
        if (start == nums.size())
        {
            result.push_back(currentSubset);
            return;
        }

        currentSubset.push_back(nums[start]);
        dfs(nums, start + 1);
        currentSubset.pop_back();

        dfs(nums, start + 1);
    }
};