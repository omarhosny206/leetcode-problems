// https://leetcode.com/problems/reverse-currentWords-in-a-string-iii/

class Solution
{
public:
    string reverseWords(string s)
    {
        string result = "";
        vector<string> splittedWords;

        split(s, splittedWords);

        for (string &word : splittedWords)
            reverse(word);
        
        for (string &word : splittedWords)
            result += word;

        return result;
    }

    void reverse(string &word)
    {
        int i = 0;
        int j = word.length() - 1;
        
        while (i < j)
        {
            char temp = word[i];
            word[i++] = word[j];
            word[j--] = temp;
        }
    }

    void split(string statement, vector<string> &splittedWords)
    {
        string currentWord = "";

        for (char &c : statement)
        {
            if (c == ' ')
            {
                splittedWords.push_back(currentWord);
                splittedWords.push_back(" ");
                currentWord = "";
            }

            else
                currentWord += c;
        }

        splittedWords.push_back(currentWord);
    }
};