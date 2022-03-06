// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/

class Solution
{
public:
    int countOrders(int n)
    {
        long result = 1;
        const int MOD = 1e9 + 7;

        for (int i = 2; i <= n; i++)
        {
            int gaps = 2 * i - 1;
            result = ((i * gaps) % MOD * result % MOD) % MOD;
        }

        return result;
    }
};