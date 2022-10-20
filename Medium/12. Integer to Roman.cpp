// https://leetcode.com/problems/integer-to-roman/

class Solution
{
public:
    string intToRoman(int num)
    {
        string result = "";
        vector<int> vals = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> romanSymbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        int i = 0;
        while (num > 0)
        {
            while (num >= vals[i])
            {
                num -= vals[i];
                result += romanSymbols[i];
            }

            i++;
        }

        return result;
    }
};