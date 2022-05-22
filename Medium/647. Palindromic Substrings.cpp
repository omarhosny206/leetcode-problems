
class Solution
{
    int result = 0;

public:
    int countSubstrings(string s)
    {
        if (s.length() == 0)
            return 0;

        for (int i = 0; i < s.length(); ++i)
        {
            expandAroundCenter(s, i, i);
            expandAroundCenter(s, i, i + 1);
        }

        return result;
    }

    int expandAroundCenter(string &s, int left, int right)
    {
        if (s.length() == 0 || left > right)
            return 0;

        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            result++;
            left--;
            right++;
        }

        return result;
    }
};