// https://leetcode.com/problems/subsets/

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> subsets;
        vector<int> current;
        generateSubsets(0, nums, current, subsets);
        return subsets;
    }

    void generateSubsets(int index, vector<int> &nums, vector<int> current, vector<vector<int>> &subsets)
    {
        subsets.push_back(current);
        for (int i = index; i < nums.size(); ++i)
        {
            current.push_back(nums[i]);
            generateSubsets(i + 1, nums, current, subsets);
            current.pop_back();
        }
    }
};