// https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/

class Solution
{
public:
    int numOfStrings(vector<string> &patterns, string word)
    {
        int result = 0;

        for (string &pattern : patterns)
        {
            int size = word.size() - pattern.size() + 1;

            for (int i = 0; i < size; ++i)
            {
                if (pattern[0] == word[i] && pattern == word.substr(i, pattern.length()))
                {
                    result++;
                    break;
                }
            }
        }

        return result;
    }
};