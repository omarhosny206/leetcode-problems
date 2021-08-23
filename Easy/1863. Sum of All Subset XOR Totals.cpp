// https://leetcode.com/problems/sum-of-all-subset-xor-totals/

class Solution
{
    int result;

public:
    int subsetXORSum(vector<int> &nums)
    {
        result = 0;
        vector<int> currentSubset;

        DFS(nums, currentSubset, 0);

        return result;
    }

    void DFS(vector<int> &nums, vector<int> &currentSubset, int position)
    {
        result += getSum(currentSubset);

        if (position == nums.size())
            return;

        for (int i = position; i < nums.size(); ++i)
        {
            currentSubset.push_back(nums[i]);
            DFS(nums, currentSubset, i + 1);
            currentSubset.pop_back();
        }
    }

    int getSum(vector<int> &currentSubset)
    {
        int result = 0;

        for (int i = 0; i < currentSubset.size(); ++i)
            result ^= currentSubset[i];

        return result;
    }
};