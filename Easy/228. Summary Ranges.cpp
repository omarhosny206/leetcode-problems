// https://leetcode.com/problems/summary-ranges/

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        if (nums.size() == 0)
            return {};

        vector<string> result;
        int i = 0;

        for (int j = 1; j < nums.size(); ++j)
        {
            if (nums[j] != nums[j - 1] + 1)
            {
                result.push_back(getInterval(nums, i, j));
                i = j;
            }
        }

        result.push_back(getInterval(nums, i, nums.size()));

        return result;
    }

    string getInterval(vector<int> &nums, int i, int j)
    {
        if (j - i == 1)
            return to_string(nums[i]);

        return to_string(nums[i]) + "->" + to_string(nums[j - 1]);
    }
};