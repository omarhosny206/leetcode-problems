// https://leetcode.com/problems/continuous-subarray-sum/

class Solution
{
    vector<int> seen;

public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        if (nums.size() < 2)
            return false;

        unordered_map<int, int> seen;

        seen[0] = -1;
        k = abs(k);
        int currentSum = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            currentSum += nums[i];
            if (k != 0)
                currentSum %= k;

            if (seen.find(currentSum) != seen.end())
            {
                if (seen[currentSum] < i - 1)
                    return true;
            }

            else
                seen[currentSum] = i;
        }

        return false;
    }
};