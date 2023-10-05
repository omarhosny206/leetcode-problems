// https://leetcode.com/problems/continuous-subarray-sum/

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> seen;
        int sum = 0;

        seen[0] = -1;

        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];

            if (seen.find(sum % k) != seen.end())
            {
                if (i - seen[sum % k] >= 2)
                    return true;
            }

            else
                seen[sum % k] = i;
        }

        return false;
    }
};