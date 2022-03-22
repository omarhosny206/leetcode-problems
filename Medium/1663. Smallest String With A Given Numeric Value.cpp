// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/

class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        string result(n, 'a');
        k -= n;

        for (int i = n - 1; i >= 0; --i)
        {
            int value = min(k, 25);
            result[i] += (char)value;
            k -= value;
        }

        return result;
    }
};