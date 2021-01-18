// https://leetcode.com/problems/calculate-money-in-leetcode-bank/

class Solution
{
public:
    int totalMoney(int n)
    {
        int result = 0;
        int current = 1;
        int sum = current;

        for (int i = 1; i <= n; ++i)
        {
            result += sum;
            sum += 1;

            if (i % 7 == 0)
            {
                current++;
                sum = current;
            }
        }

        return result;
    }
};