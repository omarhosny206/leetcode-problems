// https://leetcode.com/problems/maximum-erasure-value/

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int i = 0;
        int j = 0;
        int sum = 0;
        int max_sum = INT_MIN;
        unordered_set<int> seen;

        while (j < nums.size())
        {
            while (seen.find(nums[j]) != seen.end())
            {
                sum -= nums[i];
                seen.erase(nums[i]);
                i++;
            }

            sum += nums[j];
            seen.insert(nums[j]);
            max_sum = max(max_sum, sum);
            j++;
        }

        return max_sum;
    }
};