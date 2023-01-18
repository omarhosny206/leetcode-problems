
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int totalSum = 0;

        int globalMax = nums[0];
        int currentMax = 0;

        int globalMin = nums[0];
        int currentMin = 0;

        for (int &num : nums)
        {
            currentMax = max(currentMax + num, num);
            globalMax = max(globalMax, currentMax);

            currentMin = min(currentMin + num, num);
            globalMin = min(globalMin, currentMin);

            totalSum += num;
        }

        bool areAllNegatives = globalMax <= 0;
        if (areAllNegatives)
            return globalMax;

        return max(globalMax, totalSum - globalMin);
    }
};