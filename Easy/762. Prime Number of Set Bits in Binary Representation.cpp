// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

class Solution
{
public:
    int countPrimeSetBits(int L, int R)
    {
        int result = 0;

        for (int i = L; i <= R; ++i)
            if (isPrime(getNumBits(i)))
                result++;

        return result;
    }

    int getNumBits(int number)
    {
        int result = 0;

        while (number != 0)
        {
            number = number & (number - 1);
            result++;
        }

        return result;
    }

    bool isPrime(int x)
    {
        return (x == 2 || x == 3 || x == 5 || x == 7 ||
                x == 11 || x == 13 || x == 17 || x == 19);
    }
};