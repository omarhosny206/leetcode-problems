// https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/

class Solution
{
public:
    int numOfStrings(vector<string> &patterns, string word)
    {
        int result = 0;

        for (string &pattern : patterns)
            if (word.find(pattern) != -1)
                result++;

        return result;
    }
};