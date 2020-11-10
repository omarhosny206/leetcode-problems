// https://leetcode.com/problems/power-of-three/

class Solution
{
public:
    bool isPowerOfThree(int n)
    {

        while (n > 1)
        {
            if (n % 3 != 0)
                return false;
            n /= 3;
        }

        return n == 1;
    }
};