// https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution
{
public:
    string reverseWords(string s)
    {

        string result = "";
        vector<string> splitWords;

        Split(s, splitWords);

        for (string word : splitWords)
            result += Reverse(word);

        return result;
    }

    string Reverse(string word)
    {
        string result = "";
        int i = word.length() - 1;
        while (i >= 0)
            result += word[i--];

        return result;
    }

    void Split(string statement, vector<string> &splitWords)
    {
        string word = "";
        for (char c : statement)
        {
            if (c == ' ')
            {
                splitWords.push_back(word);
                splitWords.push_back(" ");
                word = "";
            }

            else
                word += c;
        }

        splitWords.push_back(word);
    }
};