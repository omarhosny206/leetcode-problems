// https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/

class Solution
{
public:
    int minTimeToType(string word)
    {
        int result = 0;
        int currentPosition = 0;

        for (char &letter : word)
        {
            int letterPosition = letter - 'a';
            result += min(abs(letterPosition - currentPosition), 26 - abs(letterPosition - currentPosition)) + 1;
            currentPosition = letterPosition;
        }

        return result;
    }
};