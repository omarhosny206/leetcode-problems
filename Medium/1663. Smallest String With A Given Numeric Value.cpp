// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/

class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        string result = string(n, ' ');
        int index = 0;

        while (n--)
        {
            int value = ((n * 26) - (k - 1)) > 0 ? 1 : (k - (n * 26));
            result[index++] = char((value - 1) + 'a');
            k -= value;
        }

        return result;
    }
};