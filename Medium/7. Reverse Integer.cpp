// https://leetcode.com/problems/reverse-integer/

class Solution
{
public:
    int reverse(int x)
    {
        int result = 0;

        while (x != 0)
        {
            int pop = (x % 10);
            x /= 10;
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7))
                return 0;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8))
                return 0;
            result = result * 10 + pop;
        }

        return result;
    }
};