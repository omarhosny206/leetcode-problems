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
        if (start == nums.size())
        {
            subsets.push_back(currentSubset);
            return;
        }

        currentSubset.push_back(nums[start]);
        dfs(nums, start + 1);
        currentSubset.pop_back();

        int i = start + 1;

        while (i < nums.size() && nums[i] == nums[start])
            i++;

        dfs(nums, i);
    }
};