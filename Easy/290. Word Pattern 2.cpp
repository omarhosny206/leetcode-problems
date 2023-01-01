// https://leetcode.com/problems/word-pattern/

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> letterToWord;
        unordered_map<string, char> wordToLetter;

        vector<string> words = getWords(s);

        if (pattern.size() != words.size())
            return false;

        for (int i = 0; i < pattern.length(); ++i)
        {
            if (letterToWord.find(pattern[i]) != letterToWord.end() && letterToWord[pattern[i]] != words[i])
                return false;

            if (wordToLetter.find(words[i]) != wordToLetter.end() && wordToLetter[words[i]] != pattern[i])
                return false;

            letterToWord[pattern[i]] = words[i];
            wordToLetter[words[i]] = pattern[i];
        }

        return true;
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