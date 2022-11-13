// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution
{
public:
    string reverseWords(string s)
    {
        string result = "";
        string temp = "";
        int i = 0;
        int j = 0;

        while (true)
        {
            while (i < s.size() && s[i] == ' ')
                i++;

            if (i >= s.size())
                break;

            j = i + 1;

            while (j < s.size() && s[j] != ' ')
                j++;

            temp = s.substr(i, j - i);
            result = temp + (result.size() > 0 ? " " : "") + result;

            i = j + 1;
        }

        return result;
    }
};