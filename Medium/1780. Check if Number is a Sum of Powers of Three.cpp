// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/

class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        if (n == 1)
            return true;

        if (n % 3 == 0)
            return checkPowersOfThree(n / 3);

        else if ((n - 1) % 3 == 0)
            return checkPowersOfThree(n - 1);

        return false;
    }
};