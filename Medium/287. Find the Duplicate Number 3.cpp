// https://leetcode.com/problems/find-the-duplicate-number/

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        set<int> numbers;

        for (int num : nums)
        {
            if (numbers.find(num) != numbers.end())
                return num;
            numbers.insert(num);
        }

        return 1;
    }
};