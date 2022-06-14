// https://leetcode.com/problems/delete-operation-for-two-strings/

class Solution
{
public:
    int minDistance(string &word1, string &word2)
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));

        for (int i = 0; i <= word1.size(); i++)
        {
            for (int j = 0; j <= word2.size(); j++)
            {
                if (!i || !j)
                    dp[i][j] = i + j;

                else
                    dp[i][j] = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[word1.size()][word2.size()];
    }
};