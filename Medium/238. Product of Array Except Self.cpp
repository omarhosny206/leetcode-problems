// https://leetcode.com/problems/product-of-array-except-self/

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> result(nums.size(), 1);
        int prefixProduct = 1;
        int suffixProduct = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            result[i] = prefixProduct;
            prefixProduct *= nums[i];
        }

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            result[i] *= suffixProduct;
            suffixProduct *= nums[i];
        }

        return result;
    }
};