// https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution
{
public:
    string reverseWords(string s)
    {
        int i = 0;
        int j = 0;

        while (j < s.length())
        {
            j++;

            if (s[j] == ' ' || j == s.length())
            {
                reverse(s, i, j - 1);
                i = j + 1;
            }
        }

        return s;
    }

    void reverse(string &word, int i, int j)
    {
        while (i < j)
        {
            char temp = word[i];
            word[i++] = word[j];
            word[j--] = temp;
        }
    }
};