// https://leetcode.com/problems/permutations/

class Solution
{
    vector<vector<int>> permutations;

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        getPermutations(nums, 0);
        return permutations;
    }

    void getPermutations(vector<int> &nums, int index)
    {
        if (index == nums.size() - 1)
        {
            permutations.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); ++i)
        {
            swap(nums[i], nums[index]);
            getPermutations(nums, index + 1);
            swap(nums[i], nums[index]);
        }
    }
};