// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {

        if (digits.length() == 0)
            return {};

        string mapping[] = {
            "0",
            "1",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
        };

        vector<string> result;
        letterCombinationsRecursive(result, digits, "", 0, mapping);
        return result;
    }

    void letterCombinationsRecursive(vector<string> &result, string digits, string current, int index, string mapping[])
    {

        if (index == digits.length())
        {
            result.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];
        for (int i = 0; i < letters.length(); i++)
        {
            letterCombinationsRecursive(result, digits, current + letters[i], index + 1, mapping);
        }
    }
};