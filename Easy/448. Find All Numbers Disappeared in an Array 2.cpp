// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        unordered_set<int> numbers;
        vector<int> missingNumbers;
        for (int n : nums)
            numbers.insert(n);
        for (int i = 1; i <= nums.size(); ++i)
            if (numbers.find(i) == numbers.end())
                missingNumbers.push_back(i);
        return missingNumbers;
    }
};