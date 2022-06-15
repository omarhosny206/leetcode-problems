// https://leetcode.com/problems/longest-string-chain/

class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        int result = 1;
        unordered_map<string, int> dp;

        sort(words.begin(), words.end(), compare);

        for (string &word : words)
        {
            dp[word] = 1;

            for (int i = 0; i < word.size(); i++)
            {
                string previous = word.substr(0, i) + word.substr(i + 1);

                if (dp.find(previous) != dp.end())
                {
                    dp[word] = dp[previous] + 1;
                    result = max(result, dp[word]);
                }
            }
        }

        return result;
    }

    static bool compare(string &first, string &second)
    {
        return first.size() < second.size();
    }
};