// https://leetcode.com/problems/reverse-prefix-of-word/

class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int i = 0;
        int j = 0;

        while (j < word.size() && word[j] != ch)
            j++;

        if (j < word.size())
            Reverse(word, i, j);

        return word;
    }

    void Reverse(string &word, int i, int j)
    {
        while (i < j)
        {
            char temp = word[i];
            word[i++] = word[j];
            word[j--] = temp;
        }
    }
};