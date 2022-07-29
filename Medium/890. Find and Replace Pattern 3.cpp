// https://leetcode.com/problems/find-and-replace-pattern/

class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> result;

        for (string &word : words)
            if (hasSamePattern(word, pattern))
                result.push_back(word);

        return result;
    }

    bool hasSamePattern(string &word, string &pattern)
    {
        unordered_map<char, char> wordToPattern;
        unordered_map<char, char> patternToWord;

        for (int i = 0; i < word.length(); ++i)
        {
            if (wordToPattern.find(word[i]) == wordToPattern.end())
                wordToPattern[word[i]] = pattern[i];

            if (patternToWord.find(pattern[i]) == patternToWord.end())
                patternToWord[pattern[i]] = word[i];

            if (wordToPattern[word[i]] != pattern[i] || patternToWord[pattern[i]] != word[i])
                return false;
        }

        return true;
    }
};