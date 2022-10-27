// https://leetcode.com/problems/continuous-subarray-sum/

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> seen;
        int currentSum = 0;
        const int MIN_SIZE = 2;

        seen[0] = -1;

        for (int i = 0; i < nums.size(); ++i)
        {
            currentSum += nums[i];

            if (seen.find(currentSum % k) != seen.end() && i - seen[currentSum % k] >= MIN_SIZE)
                return true;

            if (seen.find(currentSum % k) == seen.end())
                seen[currentSum % k] = i;
        }

        return false;
    }
};