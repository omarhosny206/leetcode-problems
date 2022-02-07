// https://leetcode.com/problems/find-the-difference/

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        char c = 0;

        for (char a : s)
            c ^= a;

        for (char b : t)
            c ^= b;

        return c;
    }
};