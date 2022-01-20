// https://leetcode.com/problems/word-pattern/

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> word;
        unordered_map<string, char> letter;

        vector<string> words = getWords(s);

        if (words.size() != pattern.length())
            return false;

        for (int i = 0; i < pattern.length(); ++i)
        {
            if (word.find(pattern[i]) != word.end() && word[pattern[i]] != words[i])
                return false;

            if (letter.find(words[i]) != letter.end() && letter[words[i]] != pattern[i])
                return false;

            word[pattern[i]] = words[i];
            letter[words[i]] = pattern[i];
        }

        return true;
    }

    vector<string> getWords(string &sentence)
    {
        vector<string> words;
        string currentWord = "";

        for (int i = 0; i < sentence.length(); i++)
        {
            if (sentence[i] == ' ')
            {
                words.push_back(currentWord);
                currentWord = "";
            }

            else
            {
                currentWord += s[i];
            }
        }

        words.push_back(currentWord);

        return words;
    }
};