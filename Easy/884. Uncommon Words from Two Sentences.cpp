// https://leetcode.com/problems/uncommon-words-from-two-sentences/

class Solution
{
public:
    vector<string> uncommonFromSentences(string A, string B)
    {
        vector<string> result;
        unordered_map<string, int> words_freq;

        string temp = "";
        for (char c : A)
        {
            if (c == ' ')
            {
                words_freq[temp]++;
                temp = "";
            }
            else
                temp += c;
        }

        words_freq[temp]++;

        temp = "";
        for (char c : B)
        {
            if (c == ' ')
            {
                words_freq[temp]++;
                temp = "";
            }
            else
                temp += c;
        }
        words_freq[temp]++;

        for (auto word : words_freq)
            if (word.second == 1)
                result.push_back(word.first);

        return result;
    }
};