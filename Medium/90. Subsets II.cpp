// https://leetcode.com/problems/subsets-ii/

class Solution
{
    vector<vector<int>> subsets;

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        if (nums.size() == 0)
            return {};
        sort(nums.begin(), nums.end());
        vector<int> currentSet;
        subsetsWithDup_Helper(nums, currentSet, 0);
        return subsets;
    }

    void subsetsWithDup_Helper(vector<int> &nums, vector<int> &currentSet, int position)
    {

        subsets.push_back(currentSet);

        if (position == nums.size())
            return;

        for (int i = position; i < nums.size(); ++i)
        {
            currentSet.push_back(nums[i]);
            subsetsWithDup_Helper(nums, currentSet, i + 1);
            currentSet.pop_back();

            int j = i + 1;
            while (j < nums.size() && nums[i] == nums[j])
            {
                ++i;
                ++j;
            }
        }
    }
};