// https://leetcode.com/problems/longest-common-subsequence/

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> memo(text1.size() + 1, vector<int>(text2.size() + 1, -1));

        return LCS(memo, text1, text2, text1.size(), text2.size());
    }

    int LCS(vector<vector<int>> &memo, string &text1, string &text2, int i, int j)
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