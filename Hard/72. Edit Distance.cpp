// https://leetcode.com/problems/edit-distance/

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int word1_length = word1.size();
        int word2_length = word2.size();

        // Create a DP array to memoize result of previous computations
        int DP[2][word1_length + 1];

        // To fill the DP array with 0
        memset(DP, 0, sizeof DP);

        // Base condition when second string is empty then we remove all characters
        for (int i = 0; i <= word1_length; i++)
            DP[0][i] = i;

        // Start filling the DP
        for (int i = 1; i <= word2_length; i++)
        {
            // This loop compares the char from word2 with word1 characters
            for (int j = 0; j <= word1_length; j++)
            {
                // if word1 is empty then we have to perform add character operation to get word2
                if (j == 0)
                    DP[i % 2][j] = i;

                // if character from both string is same then we do not perform any operation (Match) . here i % 2 is for bound the row number.
                else if (word1[j - 1] == word2[i - 1])
                    DP[i % 2][j] = DP[(i - 1) % 2][j - 1];

                // if character from both string is not same then we take the minimum from three specified operation (Insert, Remove, Replace)
                else
                    DP[i % 2][j] = 1 + min(DP[(i - 1) % 2][j], min(DP[i % 2][j - 1], DP[(i - 1) % 2][j - 1]));
            }
        }

        return DP[word2_length % 2][word1_length];
    }
};
