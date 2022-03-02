// https://leetcode.com/problems/is-subsequence/

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0;
        int j = 0;
        int counter = 0;

        while (i < s.length() && j < t.length())
        {
            if (s[i] == t[j])
            {
                i++;
                counter++;
            }

            j++;
        }

        return counter == s.size();
    }
};