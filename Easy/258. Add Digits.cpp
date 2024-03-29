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
        int result = 0;

        while (num > 0)
        {
            result += num % 10;
            num /= 10;
        }

        return result;
    }
};