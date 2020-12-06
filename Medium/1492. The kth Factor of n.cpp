// https://leetcode.com/problems/the-kth-factor-of-n/

class Solution
{
public:
    int kthFactor(int n, int k)
    {
        int numFactors = 0;
        int factor = 1;
        int i = 1;
        while (i <= n && numFactors < k)
        {
            if (n % i == 0)
            {
                numFactors++;
                factor = i;
            }
            i++;
        }

        return (numFactors < k) ? -1 : factor;
    }
};