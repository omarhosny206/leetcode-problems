
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (seen.find(target - nums[i]) != seen.end())
                return {seen[target - nums[i]], i};

            seen[nums[i]] = i;
        }

        return {};
    }
};