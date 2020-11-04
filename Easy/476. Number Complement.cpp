// https://leetcode.com/problems/number-complement/

class Solution
{
public:
    int findComplement(int num)
    {
        int result = 0;
        int power = 0;

        while (num > 0)
        {
            if (num % 2 == 0)
                result += pow(2, power);
            power++;
            num /= 2;
        }

        return result;
    }
};