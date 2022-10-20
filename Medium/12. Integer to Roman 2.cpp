// https://leetcode.com/problems/integer-to-roman/

class Solution
{
public:
    string intToRoman(int num)
    {
        string result = "";
        vector<string> romanSymbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        unordered_map<string, int> value =
            {{"M", 1000},
             {"CM", 900},
             {"D", 500},
             {"CD", 400},
             {"C", 100},
             {"XC", 90},
             {"L", 50},
             {"XL", 40},
             {"X", 10},
             {"IX", 9},
             {"V", 5},
             {"IV", 4},
             {"I", 1}};

        int i = 0;
        while (num > 0)
        {
            while (num >= value[romanSymbols[i]])
            {
                num -= value[romanSymbols[i]];
                result += romanSymbols[i];
            }

            i++;
        }

        return result;
    }
};