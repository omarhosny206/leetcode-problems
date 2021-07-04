// https://leetcode.com/problems/longest-word-in-dictionary/

class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        string result = "";
        unordered_set<string> dictionary;

        sort(words.begin(), words.end());

        for (string &word : words)
        {
            if (word.length() == 1 || dictionary.find(word.substr(0, word.length() - 1)) != dictionary.end())
            {
                if (result.length() < word.length())
                    result = word;

                dictionary.insert(word);
            }
        }

        return result;
    }
};