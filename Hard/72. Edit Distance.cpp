// https://leetcode.com/problems/edit-distance/

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int word1_length = word1.size();
        int word2_length = word2.size();

        int DP[2][word1_length + 1];

        memset(DP, 0, sizeof DP);

        for (int i = 0; i <= word1_length; i++)
            DP[0][i] = i;

        for (int i = 1; i <= word2_length; i++)
        {
            for (int j = 0; j <= word1_length; j++)
            {
                if (j == 0)
                    DP[i % 2][j] = i;

                else if (word1[j - 1] == word2[i - 1])
                    DP[i % 2][j] = DP[(i - 1) % 2][j - 1];

                else
                    DP[i % 2][j] = 1 + min(DP[(i - 1) % 2][j], min(DP[i % 2][j - 1], DP[(i - 1) % 2][j - 1]));
            }
        }

        return DP[word2_length % 2][word1_length];
    }
};
