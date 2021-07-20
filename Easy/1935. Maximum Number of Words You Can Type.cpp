// https://leetcode.com/problems/maximum-number-of-words-you-can-type/

class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        int result = 0;
        bool canBeTyped = true;
        unordered_set<char> broken;

        for (char &c : brokenLetters)
            broken.insert(c);

        for (char &c : text)
        {
            if (c == ' ')
            {
                result += canBeTyped;
                canBeTyped = true;
            }

            else
                canBeTyped = canBeTyped && (broken.find(c) == broken.end());
        }

        result += canBeTyped;

        return result;
    }
};