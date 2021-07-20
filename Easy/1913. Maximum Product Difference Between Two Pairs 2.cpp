// https://leetcode.com/problems/maximum-product-difference-between-two-pairs/

class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        int result = 0;

        sort(nums.begin(), nums.end());

        result = (nums[nums.size() - 1] * nums[nums.size() - 2]) - (nums[0] * nums[1]);

        return result;
    }
};