// https://leetcode.com/problems/maximum-length-of-pair-chain/

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {

        sort(pairs.begin(), pairs.end(), [&](vector<int> &a, vector<int> &b) { return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]); });

        vector<int> dp(pairs.size(), 1);

        for (int i = 1; i < pairs.size(); i++)
            for (int j = 0; j < i; j++)
                if (pairs[i][0] > pairs[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);

        int max = 0;
        for (int n : dp)
            if (max < n)
                max = n;

        return max;
    }
};