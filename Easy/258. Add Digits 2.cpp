// https://leetcode.com/problems/add-digits/

class Solution
{
public:
    int addDigits(int num)
    {
        while (num / 10 > 0)
            num = getDigitsSum(num);

        return num;
    }

    int getDigitsSum(int num)
    {
        if (num == 0)
            return 0;

        return num % 10 + getDigitsSum(num / 10);
    }
};