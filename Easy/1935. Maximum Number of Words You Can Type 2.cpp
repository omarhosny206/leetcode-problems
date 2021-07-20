// https://leetcode.com/problems/maximum-number-of-words-you-can-type/

class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        int result = 0;
        string word = "";
        unordered_set<char> broken;

        for (char &c : brokenLetters)
            broken.insert(c);

        for (char &c : text)
        {
            if (c == ' ')
            {
                result += canBeTyped(word, broken);
                word = "";
            }

            else
                word += c;
        }

        result += canBeTyped(word, broken);

        return result;
    }

    bool canBeTyped(string &word, unordered_set<char> &broken)
    {
        for (char &c : word)
            if (broken.find(c) != broken.end())
                return false;

        return true;
    }
};