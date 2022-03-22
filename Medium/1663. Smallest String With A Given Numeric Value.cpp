
class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        string result(n, 'a');
        k -= n;

        for (int i = n - 1; i >= 0; --i)
        {
            int temp = min(k, 25);
            result[i] += temp;
            k -= temp;
        }

        return result;
    }
};