// https://leetcode.com/problems/is-subsequence/

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s.empty())
            return true;

        if (s.size() > t.size())
            return false;

        int i = 0;
        int j = 0;

        while (j < t.size())
        {
            if (s[i] == t[j])
            {
                i++;

                if (i == s.size())
                    return true;
            }

            j++;
        }

        return false;
    }
};