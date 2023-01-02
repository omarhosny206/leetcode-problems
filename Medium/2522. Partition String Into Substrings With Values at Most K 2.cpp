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

            if (value > k)
            {
                result++;
                i = j;
                value = number[number.size() - 1] - '0';
            }

            if (value > k)
                return -1;

            j++;
        }

        result++;
        return result;
    }
};