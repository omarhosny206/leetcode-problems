// https://leetcode.com/problems/integer-replacement/

class Solution
{
public:
    int integerReplacement(int n)
    {
        if (n == INT_MAX)
            return 32;

        int counter = 0;

        while (n != 1)
        {
            if (n % 2 == 0)
                n /= 2;

            else if ((n - 1) / 2 % 2 == 0 || (n - 1) / 2 == 1)
                n--;

            else
                n++;

            counter++;
        }

        return counter;
    }
};