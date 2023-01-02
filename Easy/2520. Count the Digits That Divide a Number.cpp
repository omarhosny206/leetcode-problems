// https://leetcode.com/problems/count-the-digits-that-divide-a-number/

class Solution
{
public:
    int countDigits(int num)
    {
        int result = 0;
        string digits = to_string(num);

        for (char &digit : digits)
        {
            int value = digit - '0';

            if (num % value == 0)
                result++;
        }

        return result;
    }
};