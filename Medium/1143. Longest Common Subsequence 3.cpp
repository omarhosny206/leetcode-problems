// https://leetcode.com/problems/longest-common-subsequence/

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int memo[1001][1001];
        memset(memo, -1, sizeof(memo));

        return LCS(memo, text1, text2, text1.size(), text2.size());
    }

    int LCS(int memo[][1001], string &text1, string &text2, int i, int j)
    {
        if (i == 0 || j == 0)
            return 0;

        if (memo[i][j] != -1)
            return memo[i][j];

        if (text1[i - 1] == text2[j - 1])
            memo[i][j] = 1 + LCS(memo, text1, text2, i - 1, j - 1);

        else
            memo[i][j] = max(LCS(memo, text1, text2, i - 1, j), LCS(memo, text1, text2, i, j - 1));

        return memo[i][j];
    }
};