// https://leetcode.com/problems/subsets-ii/

class Solution
{
    vector<vector<int>> subsets;
    vector<int> currentSubset;

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return subsets;
    }

    void dfs(vector<int> &nums, int start)
    {
        subsets.push_back(currentSubset);

        for (int i = start; i < nums.size(); ++i)
        {
            if (i > start && nums[i] == nums[i - 1])
                continue;

            currentSubset.push_back(nums[i]);
            dfs(nums, i + 1);
            currentSubset.pop_back();
        }
    }
};