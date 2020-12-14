// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int count = 0;
        int minimum = INT_MAX;

        for (int i = 0; i < nums.size(); ++i)
            minimum = (nums[i] < minimum) ? nums[i] : minimum;

        for (int i = 0; i < nums.size(); ++i)
            count += nums[i] - minimum;

        return count;
    }
};