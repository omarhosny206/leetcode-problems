// https://leetcode.com/problems/permutations-ii/

class Solution
{
    vector<vector<int>> result;
    unordered_map<int, int> freq;

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<int> current;

        for (int &num : nums)
            freq[num]++;

        dfs(nums, current, 0);
        return result;
    }

    void dfs(vector<int> &nums, vector<int> &current, int i)
    {
        if (i == nums.size())
        {
            result.push_back(current);
            return;
        }

        for (auto &pair : freq)
        {
            if (pair.second == 0)
                continue;

            current.push_back(pair.first);
            pair.second--;

            dfs(nums, current, i + 1);

            current.pop_back();
            pair.second++;
        }
    }
};