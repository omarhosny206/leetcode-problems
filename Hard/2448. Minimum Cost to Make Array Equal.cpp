// https://leetcode.com/problems/minimum-cost-to-make-array-equal/

class Solution
{
public:
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        return binarySearch(nums, cost);
    }

    long long binarySearch(vector<int> &nums, vector<int> &cost)
    {
        long long result = LLONG_MAX;
        int left = 1;
        int right = 1e6;

        while (left < right)
        {
            int middle = left + (right - left) / 2;
            long long first = getCost(nums, cost, middle);
            long long second = getCost(nums, cost, middle + 1);

            result = min(first, second);

            if (first < second)
                right = middle;

            else
                left = middle + 1;
        }

        return result;
    }

    long long getCost(vector<int> &nums, vector<int> &cost, int target)
    {
        long long result = 0;

        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != target)
                result += 1L * abs(target - nums[i]) * cost[i];

        return result;
    }
};