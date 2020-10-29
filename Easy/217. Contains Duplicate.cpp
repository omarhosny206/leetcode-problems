// https://leetcode.com/problems/contains-duplicate/

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {

        unordered_set<int> numbers;
        for (int n : nums)
        {
            if (numbers.find(n) != numbers.end())
                return true;
            numbers.insert(n);
        }
        return false;
    }
};