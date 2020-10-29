// https://leetcode.com/problems/powx-n/

class Solution
{
public:
    double myPow(double x, int n)
    {
        return myPowRecursive(x, n);
    }

    double myPowRecursive(double x, long n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n < 0)
            return myPowRecursive(1 / x, -n);
        double result = myPowRecursive(x * x, n / 2);
        if (n % 2 != 0)
            result *= x;
        return result;
    }
};