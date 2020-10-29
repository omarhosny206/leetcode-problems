// https://leetcode.com/problems/edit-distance/

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int word1_length = word1.size();
        int word2_length = word2.size();

        // Create a DP array to memoize result of previous computations
        int DP[word1_length + 1][word2_length + 1];

        // Start filling the DP
        for (int i = 0; i <= word1_length; i++)
        {
            // This loop compares the char from word2 with word1 characters
            for (int j = 0; j <= word2_length; j++)
            {
                // If word1 is empty, only option is to insert all characters of word2
                if (i == 0)
                    DP[i][j] = j;

                // If word2 is empty, only option is to remove all characters of word2
                else if (j == 0)
                    DP[i][j] = i;

                // if character from both Strings is same then we do not perform any operation (Match)
                else if (word1[i - 1] == word2[j - 1])
                    DP[i][j] = DP[i - 1][j - 1];

                // if character from both Strings is not same then we take the minimum from three specified operations (Insert, Remove, Replace)
                else
                    DP[i][j] = 1 + min(DP[i][j - 1], min(DP[i - 1][j], DP[i - 1][j - 1]));
            }
        }

        return DP[word1_length][word2_length];
    }
};
