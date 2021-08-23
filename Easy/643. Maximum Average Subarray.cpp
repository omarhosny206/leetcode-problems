// https://leetcode.com/problems/maximum-average-subarray-i/

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double result = INT_MIN;
        double sum = 0.0;
        int i = 0;
        int j = 0;

        while (j < nums.size())
        {
            sum += nums[j];

            if (j - i + 1 == k)
            {
                result = max(result, sum / k);
                sum -= nums[i];
                i++;
            }

            j++;
        }

        return result;
    }
};