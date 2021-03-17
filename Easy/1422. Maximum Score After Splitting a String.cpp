// https://leetcode.com/problems/maximum-score-after-splitting-a-string/

class Solution
{
public:
    int maxScore(string s)
    {
        int maximumScore = 0;
        int num_ones = 0;
        int num_zeroes = 0;

        for (int i = 0; i < s.length(); ++i)
            num_ones += s[i] - '0';

        for (int i = 0; i < s.length() - 1; ++i)
        {
            (s[i] == '0') ? num_zeroes += 1 : num_ones -= 1;
            maximumScore = max(maximumScore, num_ones + num_zeroes);
        }

        return maximumScore;
    }
};