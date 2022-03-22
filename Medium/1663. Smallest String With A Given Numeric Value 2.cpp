
class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        string result = string(n, ' ');
        int index = 0;

        while (n--)
        {
            for (int i = 1; i <= 26; ++i)
            {
                if (k - i <= n * 26)
                {
                    result[index++] = char((i - 1) + 'a');
                    k -= i;
                    break;
                }
            }
        }

        return result;
    }
};