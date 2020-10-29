// https://leetcode.com/problems/find-the-difference/

class Solution
{
public:
    char findTheDifference(string s, string t)
    {

        unordered_map<char, int> map;

        for (char c : s)
            map.insert(make_pair(c, map[c]++));

        for (char c : t)
        {
            if (map[c] == 0)
                return c;
            map[c]--;
        }

        return ' ';
    }
};