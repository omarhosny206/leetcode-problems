// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int counter = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] > nums[(i + 1) % nums.size()])
                counter++;

        return (counter <= 1);
    }
};