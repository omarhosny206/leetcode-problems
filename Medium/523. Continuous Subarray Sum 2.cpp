// https://leetcode.com/problems/continuous-subarray-sum/

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> seen;
        int currentSum = 0;

        seen[0] = -1;

        for (int i = 0; i < nums.size(); ++i)
        {
            currentSum += nums[i];
            currentSum %= k;

            if (seen.find(currentSum) != seen.end() && seen[currentSum] < i - 1)
                return true;

            else if (seen.find(currentSum) == seen.end())
                seen[currentSum] = i;
        }

        return false;
    }
};