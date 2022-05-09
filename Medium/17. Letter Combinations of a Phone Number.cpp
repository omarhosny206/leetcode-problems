// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution
{
    vector<string> result;

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

        dfs(digits, mapping, "", 0);
        return result;
    }

    void dfs(string &digits, string mapping[], string current, int i)
    {
        if (i == digits.length())
        {
            result.push_back(current);
            return;
        }

        for (char &c : mapping[digits[i] - '0'])
        {
            current += c;
            dfs(digits, mapping, current, i + 1);
            current.pop_back();
        }
    }
};