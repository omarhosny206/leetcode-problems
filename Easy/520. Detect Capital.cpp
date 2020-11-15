// https://leetcode.com/problems/detect-capital/

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        return CheckWord(word);
    }

    bool CheckWord(string word)
    {
        int capitals = 0;
        int smalls = 0;
        for (char c : word)
        {
            if (isupper(c))
                capitals++;
            else
                smalls++;
        }

        if (capitals == word.length() || smalls == word.length())
            return true;

        else if (capitals == 1 && isupper(word[0]))
            return true;

        return false;
    }
};