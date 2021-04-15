// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int maxScore = INT_MIN;
        int firstBox = 0;
        int secondBox = 0;

        for (int num : nums)
        {
            firstBox += num;
            secondBox += num;
            maxScore = max({maxScore, firstBox, abs(secondBox)});

            if (firstBox < 0)
                firstBox = 0;

            if (secondBox > 0)
                secondBox = 0;
        }

        return maxScore;
    }
};