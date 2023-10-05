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
            sum = (sum + nums[i]) % k;

            if (seen.find(sum) != seen.end())
            {
                if (i - seen[sum] >= 2)
                    return true;
            }

            else
                seen[sum] = i;
        }

        return false;
    }
};