// https://leetcode.com/problems/longest-word-in-dictionary/

class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        string result = "";
        unordered_map<string, int> dictionary;

        sort(words.begin(), words.end());

        for (string &word : words)
        {
            if (word.length() == 1 || dictionary[word.substr(0, word.length() - 1)] == 1)
            {
                if (result.length() < word.length())
                    result = word;

                dictionary[word] = 1;
            }
        }

        return result;
    }
};