// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int start = INT_MAX;
        int end = INT_MIN;

        vector<int> sortedNums = nums;

        sort(sortedNums.begin(), sortedNums.end());

        for (int i = 0; i < nums.size(); ++i)
        {
            if (sortedNums[i] != nums[i])
            {
                start = min(start, i);
                end = max(end, i);
            }
        }

        if (start == INT_MAX)
            return 0;

        return end - start + 1;
    }
};