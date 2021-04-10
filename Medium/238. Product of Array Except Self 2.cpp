// https://leetcode.com/problems/product-of-array-except-self/

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> result;
        int numZeroes = 0;
        int totalProduct = 1;

        for (int num : nums)
        {
            if (num != 0)
                totalProduct *= num;
            else
                numZeroes++;
        }

        if (numZeroes > 1)
        {
            return vector<int>(nums.size());
        }

        if (numZeroes == 1)
            for (int num : nums)
                result.push_back(num != 0 ? 0 : totalProduct);

        else
            for (int num : nums)
                result.push_back(totalProduct / num);

        return result;
    }
};