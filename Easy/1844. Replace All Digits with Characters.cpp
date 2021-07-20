// https://leetcode.com/problems/replace-all-digits-with-characters/

class Solution
{
public:
    string replaceDigits(string s)
    {
        for (int i = 0; i < s.length(); i += 2)
            Shift(s, i, i + 1);

        return s;
    }

    void Shift(string &s, int i, int j)
    {
        int value = s[i] - 'a';
        value += s[j] - '0';
        s[j] = char(value + 'a');
    }
};