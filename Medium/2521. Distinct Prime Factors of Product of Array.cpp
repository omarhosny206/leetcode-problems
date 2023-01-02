// https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/

class Solution
{
    unordered_set<int> values;

public:
    int distinctPrimeFactors(vector<int> &nums)
    {
        for (int &num : nums)
            addPrimeFactors(num);

        return values.size();
    }

    void addPrimeFactors(int num)
    {
        int divisor = 2;

        while (num > 1)
        {
            if (num % divisor == 0)
            {
                values.insert(divisor);
                num = num / divisor;
            }

            else
                divisor++;
        }
    }
};