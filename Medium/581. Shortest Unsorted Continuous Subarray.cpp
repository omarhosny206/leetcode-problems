
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int start = 0;
        int end = nums.size() - 1;

        int minDecreasing = INT_MAX;
        int maxIncreasing = INT_MIN;

        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] < nums[i - 1])
                minDecreasing = min(minDecreasing, nums[i]);

        for (int i = nums.size() - 2; i >= 0; --i)
            if (nums[i] > nums[i + 1])
                maxIncreasing = max(maxIncreasing, nums[i]);

        if (minDecreasing == INT_MAX && maxIncreasing == INT_MIN)
            return 0;

        while (start < nums.size() && nums[start] <= minDecreasing)
            start++;

        while (end >= 0 && nums[end] >= maxIncreasing)
            end--;

        return end - start + 1;
    }
};