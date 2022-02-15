// https://leetcode.com/problems/missing-number/

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum = 0;
        int expectedSum = (nums.size() * (nums.size() + 1)) / 2;

        for (int &num : nums)
            sum += num;

        return expectedSum - sum;
    }
};