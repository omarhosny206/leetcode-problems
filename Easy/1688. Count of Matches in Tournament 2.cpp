// https://leetcode.com/problems/count-of-matches-in-tournament/

class Solution
{
public:
    int numberOfMatches(int n)
    {
        int result = 0;
        while (n > 1)
        {
            result += n / 2;
            n = (n / 2) + (n % 2);
        }

        return result;
    }
};