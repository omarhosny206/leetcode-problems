// https://leetcode.com/problems/integer-to-roman/

class Solution
{
public:
    string intToRoman(int num)
    {
        string result = "";
        int vals[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        for (int i = 0; num > 0; ++i)
        {
            while (num >= vals[i])
            {
                result += roman[i];
                num -= vals[i];
            }
        }

        return result;
    }
};