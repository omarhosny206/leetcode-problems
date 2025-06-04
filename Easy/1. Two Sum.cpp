// https://leetcode.com/problems/two-sum/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> index;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (index.find(target - nums[i]) != index.end())
                return {index[target - nums[i]], i};

            index[nums[i]] = i;
        }

        return {};
    }
};