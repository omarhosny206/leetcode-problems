// https://leetcode.com/problems/missing-number/

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int expectedSum = (nums.size() * (nums.size() + 1)) / 2;
        int givenSum = 0;
        for (int i = 0; i < nums.size(); i++)
            givenSum += nums[i];

        return expectedSum - givenSum;
    }
};