// https://leetcode.com/problems/contains-duplicate/

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {

        map<int, int> numbers;
        for (int n : nums)
        {
            numbers[n]++;
            if (numbers[n] == 2)
                return true;
        }
        return false;
    }
};