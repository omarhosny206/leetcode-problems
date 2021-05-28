// https://leetcode.com/problems/longest-common-subsequence/

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> table(text1.size() + 1, vector<int>(text2.size() + 1));

        for (int i = 1; i <= text1.size(); ++i)
        {
            for (int j = 1; j <= text2.size(); ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                    table[i][j] = 1 + table[i - 1][j - 1];

                else
                    table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }

        return table[text1.size()][text2.size()];
    }
};