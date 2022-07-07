// https://leetcode.com/problems/interleaving-string/

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return check(dp, s1, s2, s3, 0, 0, 0);
    }

    bool check(vector<vector<int>> &dp, string &s1, string &s2, string &s3, int i, int j, int k)
    {
        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == s1.length() and j == s2.length() and k == s3.length())
            return true;

        bool result = false;

        if (i < s1.length() && s1[i] == s3[k])
            result = result || check(dp, s1, s2, s3, i + 1, j, k + 1);

        if (j < s2.length() && s2[j] == s3[k])
            result = result || check(dp, s1, s2, s3, i, j + 1, k + 1);

        dp[i][j] = result;
        return dp[i][j];
    }
};