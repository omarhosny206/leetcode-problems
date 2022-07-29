// https://leetcode.com/problems/find-and-replace-pattern/

class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> result;

        vector<int> patternValue = getValue(pattern);

        for (string &word : words)
            if (patternValue == getValue(word))
                result.push_back(word);

        return result;
    }

    vector<int> getValue(string &word)
    {
        vector<int> result;

        unordered_map<char, int> value;
        int i = 1;

        for (char &c : word)
        {
            if (value.find(c) == value.end())
                value[c] = i++;

            result.push_back(value[c]);
        }

        return result;
    }
};