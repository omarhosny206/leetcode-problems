// https://leetcode.com/problems/first-missing-positive/

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int maxNumber = INT_MIN;

        for (int num : nums)
            maxNumber = max(maxNumber, num);

        int i = 1;
        for (i; i <= maxNumber; i++)
            if (find(nums.begin(), nums.end(), i) == nums.end())
                break;

        return i;
    }
};