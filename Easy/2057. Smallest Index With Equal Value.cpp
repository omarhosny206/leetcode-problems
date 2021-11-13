// https://leetcode.com/problems/smallest-index-with-equal-value/

class Solution
{
public:
    int smallestEqual(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] == i % 10)
                return i;

        return -1;
    }
};