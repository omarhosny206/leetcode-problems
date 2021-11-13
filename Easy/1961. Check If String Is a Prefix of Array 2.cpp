// https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/

class Solution
{
public:
    bool isPrefixString(string s, vector<string> &words)
    {
        unordered_set<string> sentences;
        string sentence = "";

        for (string &word : words)
        {
            sentence += word;
            sentences.insert(sentence);
        }

        return sentences.find(s) != sentences.end();
    }
};