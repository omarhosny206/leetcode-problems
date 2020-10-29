// https://leetcode.com/problems/isomorphic-strings/

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> l1;
        unordered_map<char, char> l2;

        for (int i = 0; i < s.size(); i++)
        {
            if (l1.find(s[i]) != l1.end() && l1[s[i]] != t[i])
                return false;

            if (l2.find(t[i]) != l2.end() && l2[t[i]] != s[i])
                return false;

            l2.insert(pair<char, char>(t[i], s[i]));
            l1.insert(pair<char, char>(s[i], t[i]));
        }
        return true;
    }
};