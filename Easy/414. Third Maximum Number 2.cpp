// https://leetcode.com/problems/third-maximum-number/

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        set<int, greater<int>> uniqueNumbers(nums.begin(), nums.end());
        if (uniqueNumbers.size() < 3)
            return *uniqueNumbers.begin();
        return *next(begin(uniqueNumbers), 2);
    }
};