// https://leetcode.com/problems/delete-operation-for-two-strings/

class Solution
{
    vector<vector<int>> dp;

public:
    int minDistance(string &word1, string &word2)
    {
        dp.resize(word1.size() + 1, vector<int>(word2.size() + 1, 1000));
        return solve(word1, word2, 0, 0);
    }

    int solve(string &word1, string &word2, int i, int j)
    {
        if (i == word1.size() && j == word2.size())
            return 0;

        if (i == word1.size() || j == word2.size())
            return max(word1.size() - i, word2.size() - j);

        if (dp[i][j] != 1000)
            return dp[i][j];

        if (word1[i] == word2[j])
            return solve(word1, word2, i + 1, j + 1);

        return dp[i][j] = 1 + min(solve(word1, word2, i + 1, j), solve(word1, word2, i, j + 1));
    }
};