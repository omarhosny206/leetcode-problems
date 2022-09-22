// https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/

class Solution
{
public:
    int longestContinuousSubstring(string s)
    {
        int result = 1;
        int i = 0;
        int j = 1;

        while (j < s.length())
        {
            if (s[j] - 'a' != (s[j - 1] - 'a') + 1)
            {
                result = max(result, j - i);
                i = j;
            }

            j++;
        }

        result = max(result, j - i);
        return result;
    }
};