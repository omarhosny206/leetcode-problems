// https://leetcode.com/problems/circular-sentence/

class Solution
{
    vector<string> words;

public:
    bool isCircularSentence(string sentence)
    {
        split(sentence);

        string first = words[0];
        string last = words[words.size() - 1];

        if (first[0] != last[last.size() - 1])
            return false;

        for (int i = 1; i < words.size(); ++i)
        {
            string previous = words[i - 1];
            string current = words[i];

            if (previous[previous.size() - 1] != current[0])
                return false;
        }

        return true;
    }

    void split(string &sentence)
    {
        string word = "";

        for (char &c : sentence)
        {
            if (c == ' ')
            {
                words.push_back(word);
                word = "";
            }

            else
                word += c;
        }

        words.push_back(word);
    }
};