// https://leetcode.com/problems/maximum-product-subarray/

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxVal = nums[0];
        int minVal = nums[0];
        int product = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                swap(maxVal, minVal);

            maxVal = max(nums[i], maxVal * nums[i]);
            minVal = min(nums[i], minVal * nums[i]);
            product = max(product, maxVal);
        }
        return product;
    }
};