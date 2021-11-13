// https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/

class Solution
{
public:
    bool isPrefixString(string s, vector<string> &words)
    {
        string sentence = "";

        for (string &word : words)
        {
            sentence += word;

            if (s == sentence)
                return true;
        }

        return false;
    }
};