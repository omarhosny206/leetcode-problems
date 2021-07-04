// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

class Solution
{
public:
    string removeOccurrences(string &s, string part)
    {
        int found = s.find(part);

        if (found != string::npos)
        {
            s.erase(found, part.size());
            removeOccurrences(s, part);
        }

        return s;
    }
};