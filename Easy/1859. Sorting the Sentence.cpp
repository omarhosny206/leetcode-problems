// https://leetcode.com/problems/sorting-the-sentence/

class Solution
{
public:
    string sortSentence(string s)
    {
        string result = "";
        map<int, string> positions;

        vector<string> words = getWords(s);

        mapPosition(words, positions);

        result = buildSentence(positions);

        return result;
    }

    void mapPosition(vector<string> &words, map<int, string> &positions)
    {
        for (string &word : words)
            positions[word[word.length() - 1] - '0'] = word.substr(0, word.length() - 1);
    }

    string buildSentence(map<int, string> &positions)
    {
        string result = "";

        for (auto &pair : positions)
            result += pair.second + " ";

        result.pop_back();

        return result;
    }

    vector<string> getWords(string &sentence)
    {
        vector<string> result;
        string word = "";

        for (int i = 0; i < sentence.length(); ++i)
        {
            if (sentence[i] == ' ')
            {
                result.push_back(word);
                word = "";
            }

            else
                word += sentence[i];
        }

        result.push_back(word);

        return result;
    }
};