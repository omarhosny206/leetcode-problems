// https://leetcode.com/problems/reverse-string-ii/

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        for (int i = 0; i < s.length(); i += (2 * k))
            Reverse(s, i, min(i + k - 1, (int)s.size() - 1));

        return s;
    }

    void Reverse(string &s, int i, int j)
    {
        while (i < j)
        {
            char temp = s[i];
            s[i++] = s[j];
            s[j--] = temp;
        }
    }
};