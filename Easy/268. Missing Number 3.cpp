// https://leetcode.com/problems/missing-number/

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        unordered_set<int> vals;
        for (int n : nums)
            vals.insert(n);
        for (int i = 0; i <= nums.size(); ++i)
            if (vals.find(i) == vals.end())
                return i;
        return -1;
    }
};