// https://leetcode.com/problems/majority-element/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return nums[0];

        int counter = 1;
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
                counter++;

            else
                counter = 1;

            if (counter > nums.size() / 2)
                return nums[i];
        }

        return -1;
    }
};