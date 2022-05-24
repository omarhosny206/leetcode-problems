// https://leetcode.com/problems/ones-and-zeroes/

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (string &binary : strs)
        {
            int zeros = countZeros(binary);
            int ones = binary.size();

            for (int i = m; i >= zeros; i--)
                for (int j = n; j >= (ones - zeros); j--)
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones + zeros]);
        }

        return dp[m][n];
    }

    int countZeros(string &binary)
    {
        int result = 0;

        for (char &c : binary)
            if (c == '0')
                result++;

        return result;
    }
};