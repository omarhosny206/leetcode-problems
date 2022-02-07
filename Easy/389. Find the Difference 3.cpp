// https://leetcode.com/problems/find-the-difference/

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int i = 0;
        int j = 0;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        while (i < s.length() && j < t.length())
        {
            if (s[i] != t[j])
                return t[j];

            i++;
            j++;
        }

        return t[j];
    }
};