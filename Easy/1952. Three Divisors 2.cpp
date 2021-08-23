// https://leetcode.com/problems/three-divisors/

class Solution
{
public:
    bool isThree(int n)
    {
        int counter = 1;

        for (int i = 2; i <= n; ++i)
        {
            if (i % n == 0 || n % i == 0)
                counter++;

            if (counter > 3)
                return false;
        }

        return counter == 3;
    }
};