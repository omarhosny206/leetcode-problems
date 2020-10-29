// https://leetcode.com/problems/valid-perfect-square/

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        long long n = num;
        for (long long i = 1; i * i <= n; i++)
            if (i * i == n)
                return true;
        return false;
    }
};