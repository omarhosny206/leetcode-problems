// https://leetcode.com/problems/maximum-erasure-value/

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int result = INT_MIN;
        unordered_set<int> seen;

        int i = 0;
        int j = 0;
        int sum = 0;

        while (j < nums.size())
        {
            while (seen.find(nums[j]) != seen.end())
            {
                sum -= nums[i];
                seen.erase(nums[i]);
                i++;
            }

            seen.insert(nums[j]);

            sum += nums[j];
            result = max(result, sum);
            j++;
        }

        return result;
    }
};