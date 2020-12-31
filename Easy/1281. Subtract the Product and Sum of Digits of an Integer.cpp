// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int sum = 0;
        int product = 1;

        int number = n;

        while (number > 0)
        {
            sum += number % 10;
            number /= 10;
        }

        number = n;

        while (number > 0)
        {
            product *= number % 10;
            number /= 10;
        }

        return product - sum;
    }
};