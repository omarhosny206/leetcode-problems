// https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/

class Solution
{
public:
    int maxNonOverlapping(vector<int> &nums, int target)
    {
        int result = 0;
        unordered_map<int, int> seen;
        seen[0] = -1;
        int sum = 0;
        int last = -1;

        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if (seen.find(sum - target) != seen.end() && last < seen[sum - target] + 1)
            {
                result++;
                last = i;
            }

            seen[sum] = i;
        }

        return result;
    }
};