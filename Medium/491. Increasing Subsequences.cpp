// https://leetcode.com/problems/increasing-subsequences/

class Solution
{
    vector<vector<int>> increasingSubsequences;
    set<vector<int>> uniqueSubsequences;

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        vector<int> subsequence;
        DFS(nums, subsequence, INT_MIN, 0);
        return increasingSubsequences;
    }

    void DFS(vector<int> &nums, vector<int> &subsequence, int lastValue, int position)
    {

        if (subsequence.size() > 1 && uniqueSubsequences.find(subsequence) == uniqueSubsequences.end())
        {
            increasingSubsequences.push_back(subsequence);
            uniqueSubsequences.insert(subsequence);
        }

        if (position >= nums.size())
            return;

        if (nums[position] >= lastValue)
        {
            subsequence.push_back(nums[position]);
            DFS(nums, subsequence, nums[position], position + 1);
            subsequence.pop_back();
        }

        DFS(nums, subsequence, lastValue, position + 1);
    }
};