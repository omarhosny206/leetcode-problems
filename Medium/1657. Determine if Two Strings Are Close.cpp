// https://leetcode.com/problems/determine-if-two-strings-are-close/

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.length() != word2.length())
            return false;

        vector<int> firstFreq(26);
        vector<int> secondFreq(26);
        vector<int> firstChars(26);
        vector<int> secondChars(26);

        for (int i = 0; i < word1.length(); ++i)
        {
            firstFreq[word1[i] - 'a']++;
            firstChars[word1[i] - 'a'] = 1;
            secondFreq[word2[i] - 'a']++;
            secondChars[word2[i] - 'a'] = 1;
        }

        sort(firstFreq.begin(), firstFreq.end());
        sort(secondFreq.begin(), secondFreq.end());

        return (firstFreq == secondFreq) && (firstChars == secondChars);
    }
};