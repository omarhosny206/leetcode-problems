// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

class Solution
{
public:
    string removeOccurrences(string &s, string part)
    {
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == part[0] && s.substr(i, part.length()) == part)
            {
                s.erase(i, part.length());
                removeOccurrences(s, part);
            }
        }

        return s;
    }
};