// https://leetcode.com/problems/detect-capital/

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int numUpper = 0;
        int numLower = 0;

        for (char &c : word)
        {
            if (isupper(c))
                numUpper++;

            else
                numLower++;
        }

        return (numUpper == word.length()) || (numLower == word.length()) || (numUpper == 1 && isupper(word[0]));
    }
};