// https://leetcode.com/problems/two-sum/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        unordered_map<int, int> items;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (items.find(nums[i]) != items.end())
            {
                result.push_back(items[nums[i]]);
                result.push_back(i);
                return result;
            }
            items[target - nums[i]] = i;
        }
        return result;
    }
};