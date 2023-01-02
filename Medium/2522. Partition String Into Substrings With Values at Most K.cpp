// https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/

class Solution
{
public:
    int minimumPartition(string s, int k)
    {
        int result = 0;
        int i = 0;
        int j = 0;

        while (j < s.length())
        {
            string number = s.substr(i, j - i + 1);
            long long value = stoll(number);
            int windowSize = j - i + 1;

            if (value > k)
            {
                if (windowSize == 1)
                    return -1;

                result++;
                i = j;
                j--;
            }

            j++;
        }

        result++;
        return result;
    }
};