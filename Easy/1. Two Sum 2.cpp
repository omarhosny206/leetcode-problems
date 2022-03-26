// https://leetcode.com/problems/two-sum/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (seen.find(nums[i]) != seen.end())
                return {seen[nums[i]], i};

            seen[target - nums[i]] = i;
        }

        return {};
    }
};