// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/

class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        k -= n;
        string result(n, 'a');

        for (int i = n - 1; i >= 0; --i)
        {
            int temp = min(k, 25);
            result[i] += temp;
            k -= temp;
        }

        return result;
    }
};