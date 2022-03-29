// https://leetcode.com/problems/find-the-duplicate-number/

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_map<int, bool> seen;

        for (int &num : nums)
        {
            if (seen[num])
                return num;

            seen[num] = true;
        }

        return -1;
    }
};