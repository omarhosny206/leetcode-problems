// https://leetcode.com/problems/word-break/

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        if (wordDict.size() == 0)
            return false;

        unordered_set<string> dictionary;
        for (string word : wordDict)
            dictionary.insert(word);

        vector<bool> DP(s.length() + 1, false);
        DP[s.length()] = true;

        string temp = "";
        for (int i = s.length() - 1; i >= 0; --i)
        {
            temp = "";
            for (int j = i; j < s.length(); ++j)
            {
                temp += s[j];
                if (dictionary.find(temp) == dictionary.end())
                    continue;

                if (DP[j + 1] == true)
                {
                    DP[i] = true;
                    break;
                }
            }
        }

        return DP[0];
    }
};