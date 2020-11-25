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
        result.push_back("");

        for (int i = 0; i < digits.length(); i++)
        {
            while (result.front().length() == i)
            {
                string permutation = result.front();
                result.erase(result.begin());
                for (char c : mapping[digits[i] - '0'])
                    result.push_back(permutation + c);
            }
        }

        return result;
    }
};