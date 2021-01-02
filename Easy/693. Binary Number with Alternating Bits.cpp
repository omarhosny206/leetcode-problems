// https://leetcode.com/problems/binary-number-with-alternating-bits/

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        string result = toBinary(n);

        for (int i = 1; i < result.length(); ++i)
            if (result[i] == result[i - 1])
                return false;

        return true;
    }

    string toBinary(int number)
    {
        string result = "";

        while (number > 0)
        {
            result = to_string(number % 2) + result;
            number /= 2;
        }

        return result;
    }
};