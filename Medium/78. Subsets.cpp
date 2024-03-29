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
        result.push_back(currentSubset);

        for (int i = start; i < nums.size(); ++i)
        {
            currentSubset.push_back(nums[i]);
            dfs(nums, i + 1);
            currentSubset.pop_back();
        }
    }
};