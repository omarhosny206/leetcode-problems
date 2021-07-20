// https://leetcode.com/problems/print-words-vertically/

class Solution
{
public:
    vector<string> printVertically(string s)
    {
        vector<string> result;
        vector<string> words = getWords(s);
        int length = getMaxLength(words);

        for (int i = 0; i < length; ++i)
        {
            string word = "";
            for (int j = 0; j < words.size(); ++j)
            {
                if (i < words[j].length())
                    word += words[j][i];
                else
                    word += " ";
            }

            int k = word.length() - 1;
            while (!isalpha(word[k]))
                k--;

            word = word.substr(0, k + 1);
            result.push_back(word);
        }

        return result;
    }

    vector<string> getWords(string &s)
    {
        vector<string> words;
        string word = "";

        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == ' ')
            {
                words.push_back(word);
                word = "";
            }

            else
                word += s[i];
        }

        words.push_back(word);

        return words;
    }

    int getMaxLength(vector<string> &words)
    {
        int result = INT_MIN;

        for (string &word : words)
            result = max(result, (int)word.length());

        return result;
    }
};