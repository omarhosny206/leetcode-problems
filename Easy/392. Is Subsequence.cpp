// https://leetcode.com/problems/is-subsequence/

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0;
        int j = 0;
        int counter = 0;

        for (int i = 0, j = 0; i < t.size() && j < s.size(); i++)
        {

            if (s[j] == t[i])
            {
                j++;
                counter++;
            }
        }
        return counter == s.size();
    }
};