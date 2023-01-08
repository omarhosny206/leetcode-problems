// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/

class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int positives = 0;
        int negatives = 0;

        for (int &num : nums)
        {
            if (num > 0)
                positives++;

            else if (num < 0)
                negatives++;
        }

        return max(positives, negatives);
    }
};