// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/

class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        int result = INT_MIN;
        unordered_set<int> vals;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (vals.find(-nums[i]) != vals.end())
                result = max(result, abs(nums[i]));

            vals.insert(nums[i]);
        }

        return result == INT_MIN ? -1 : result;
    }
};