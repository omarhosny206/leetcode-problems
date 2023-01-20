
class Solution
{
    vector<vector<int>> result;
    set<vector<int>> uniqueSubsequences;

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        vector<int> current;

        dfs(nums, current, 0);

        for (const vector<int> &uniqueSubsequence : uniqueSubsequences)
            result.push_back(uniqueSubsequence);

        return result;
    }

    void dfs(vector<int> &nums, vector<int> &current, int start)
    {
        if (current.size() >= 2)
            uniqueSubsequences.insert(current);

        if (start >= nums.size())
            return;

        for (int i = start; i < nums.size(); ++i)
        {
            if (current.empty() || (!current.empty() && nums[i] >= current.back()))
            {
                current.push_back(nums[i]);
                dfs(nums, current, i + 1);
                current.pop_back();
            }
        }
    }
};