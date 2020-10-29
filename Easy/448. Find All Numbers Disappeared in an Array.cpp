// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> numbers(nums.size() + 1, 0);
        vector<int> missingNumbers;
        for (int n : nums)
            numbers[n]++;
        for (int i = 1; i <= nums.size(); ++i)
            if (numbers[i] == 0)
                missingNumbers.push_back(i);
        return missingNumbers;
    }
};