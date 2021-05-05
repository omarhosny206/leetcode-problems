// https://leetcode.com/problems/contains-duplicate/

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> numbers;

        for (int n : nums)
            numbers.insert(n);

        return numbers.size() < nums.size();
    }
};