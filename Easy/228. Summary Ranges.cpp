// https://leetcode.com/problems/summary-ranges/

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        if (nums.size() == 0)
            return {};

        vector<string> result;
        int a = nums[0];

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == nums.size() - 1 || nums[i] != nums[i + 1] - 1)
            {
                if (nums[i] == a)
                    result.push_back(to_string(a));
                else
                    result.push_back(to_string(a) + "->" + to_string(nums[i]));

                if (i != nums.size() - 1)
                    a = nums[i + 1];
            }
        }

        return result;
    }
};