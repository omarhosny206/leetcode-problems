// https://leetcode.com/problems/increasing-subsequences/

class Solution
{
    vector<vector<int>> result;
    set<vector<int>> uniqueSubsequences;

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        vector<int> current;
        dfs(nums, current, 0);
        return result;
    }

    void dfs(vector<int> &nums, vector<int> &current, int start)
    {
        if (current.size() >= 2 && uniqueSubsequences.find(current) == uniqueSubsequences.end())
        {
            result.push_back(current);
            uniqueSubsequences.insert(current);
        }

        if (start >= nums.size())
            return;

        if (current.empty() || (!current.empty() && nums[start] >= current.back()))
        {
            current.push_back(nums[start]);
            dfs(nums, current, start + 1);
            current.pop_back();
        }

        dfs(nums, current, start + 1);
    }
};