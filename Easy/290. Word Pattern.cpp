// https://leetcode.com/problems/word-pattern/

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        vector<int> first;
        vector<int> second;
        unordered_map<char, int> letterValue;
        unordered_map<string, int> wordValue;

        vector<string> words = getWords(s);
        int j = 0;

        if (words.size() != pattern.length())
            return false;

        for (int i = 0; i < pattern.length(); ++i)
        {
            if (letterValue.find(pattern[i]) == letterValue.end())
                letterValue[pattern[i]] = j;

            if (wordValue.find(words[i]) == wordValue.end())
                wordValue[words[i]] = j;

            first.push_back(letterValue[pattern[i]]);
            second.push_back(wordValue[words[i]]);
            j++;
        }

        return first == second;
    }

    vector<string> getWords(string &sentence)
    {
        vector<string> words;
        string word = "";

        for (char &c : sentence)
        {
            if (c == ' ')
            {
                words.push_back(word);
                word = "";
            }

            else
                word += c;
        }

        words.push_back(word);
        return words;
    }
};