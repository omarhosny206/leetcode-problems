// https://leetcode.com/problems/missing-number/

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        unordered_set<int> values;

        for (int &num : nums)
            values.insert(num);

        for (int i = 0; i <= nums.size(); ++i)
            if (values.find(i) == values.end())
                return i;

        return -1;
    }
};