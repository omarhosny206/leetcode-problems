// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/

class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        string result;

        while (n--)
        {
            for (int i = 1; i <= 26; ++i)
            {
                if (k - i <= n * 26)
                {
                    result += (i - 1) + 'a';
                    k -= i;
                    break;
                }
            }
        }

        return result;
    }
};