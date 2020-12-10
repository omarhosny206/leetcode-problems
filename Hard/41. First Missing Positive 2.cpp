// https://leetcode.com/problems/first-missing-positive/

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        set<int> numbers(nums.begin(), nums.end());
        int i = 1;

        while (true)
        {
            if (numbers.find(i) == numbers.end())
                break;
            i++;
        }

        return i;
    }
};