// https://leetcode.com/problems/minimum-average-difference/

class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        int result = 0;
        int value = INT_MAX;

        vector<long long> left(nums.size());
        vector<long long> right(nums.size());

        long long leftPrefixSum = 0;
        long long rightPrefixSum = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            leftPrefixSum += nums[i];
            left[i] = leftPrefixSum;
        }

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            right[i] = rightPrefixSum;
            rightPrefixSum += nums[i];
        }

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            int current = (left[i] / (i + 1)) - (right[i] / (nums.size() - i - 1));
            current = abs(current);

            if (current < value)
            {
                result = i;
                value = current;
            }
        }

        int current = left[nums.size() - 1] / nums.size();

        if (current < value)
        {
            result = nums.size() - 1;
            value = current;
        }

        return result;
    }
};