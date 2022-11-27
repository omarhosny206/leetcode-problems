// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/

class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int result;
        int i = 0;
        int j = 0;

        while (i < s.length() && j < t.length())
        {
            if (s[i] == t[j])
                j++;

            i++;
        }

        result = t.length() - j;
        return result;
    }
};