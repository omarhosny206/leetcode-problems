// https://leetcode.com/problems/single-number/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        int i = 0;

        sort(nums.begin(), nums.end());

        while (i < nums.size())
        {
            if (nums[i] != nums[i + 1])
                return nums[i];

            i += 2;
        }

        return 0;
    }
};