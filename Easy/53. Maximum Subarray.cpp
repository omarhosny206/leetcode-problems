// https://leetcode.com/problems/maximum-subarray/

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxScore = INT_MIN;
        int box = 0;

        for (int num : nums)
        {
            box += num;
            maxScore = max(maxScore, box);
            if (box < 0)
                box = 0;
        }

        return maxScore;
    }
};