// https://leetcode.com/problems/sum-of-digits-in-base-k/

class Solution
{
public:
    int sumBase(int n, int k)
    {
        int result = countDigits(toBaseK(n, k));
        return result;
    }

    int countDigits(int num)
    {
        int result = 0;

        while (num > 0)
        {
            result += num % 10;
            num /= 10;
        }

        return result;
    }

    int toBaseK(int num, int k)
    {
        int result = 0;

        while (num > 0)
        {
            result = result * 10 + (num % k);
            num /= k;
        }

        return result;
    }
};