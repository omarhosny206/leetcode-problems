
class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> result;

        vector<string> patternValue = getValue(pattern);

        for (string &word : words)
            if (patternValue == getValue(word))
                result.push_back(word);

        return result;
    }

    vector<string> getValue(string &word)
    {
        vector<string> result;

        unordered_map<char, int> value;
        int i = 1;

        for (char &c : word)
        {
            if (value.find(c) == value.end())
                value[c] = i++;

            result.push_back(to_string(value[c]));
        }

        return result;
    }
};