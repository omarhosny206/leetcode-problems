// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/

class Solution
{
public:
    int minimumDeletions(string s)
    {
        int aCount = 0;
        for (char c : s)
            aCount += (c == 'a') ? 1 : 0;

        int result = INT_MAX;
        int bCount = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == 'b')
            {
                result = min(result, bCount + aCount);
                bCount++;
            }
            else
                aCount--;
        }

        result = min(result, bCount);

        return result == INT_MAX ? 0 : result;
    }
};