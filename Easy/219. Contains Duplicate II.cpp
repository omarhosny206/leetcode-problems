// https://leetcode.com/problems/contains-duplicate-ii/

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> numbers;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (numbers.find(nums[i]) != numbers.end() && i - numbers[nums[i]] <= k)
                return true;

            numbers[nums[i]] = i;
        }

        return false;
    }
};