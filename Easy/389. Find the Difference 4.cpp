// https://leetcode.com/problems/find-the-difference/

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        char result = (char)abs(countAsciiCode(s) - countAsciiCode(t));
        return result;
    }

    int countAsciiCode(string &word)
    {
        int result = 0;

        for (char &c : word)
            result += c;

        return result;
    }
};