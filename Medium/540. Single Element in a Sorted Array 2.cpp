// https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int unique = 0;
        for (int num : nums)
            unique ^= num;

        return unique;
    }
};