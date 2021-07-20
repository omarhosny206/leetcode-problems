// https://leetcode.com/problems/sign-of-the-product-of-an-array/

class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int result = 1;

        for (int &num : nums)
            result *= getSign(num);

        return result;
    }

    int getSign(int &num)
    {
        if (num > 0)
            return 1;

        else if (num < 0)
            return -1;

        return 0;
    }
};