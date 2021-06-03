// https://leetcode.com/problems/rearrange-words-in-a-sentence/

class Solution
{
public:
    string arrangeWords(string text)
    {
        string result = "";
        map<int, vector<string>> words;
        string word = "";

        text[0] = tolower(text[0]);

        for (int i = 0; i < text.length(); ++i)
        {
            if (text[i] == ' ')
            {
                words[word.length()].push_back(word);
                word = "";
            }

            else
                word += text[i];
        }

        words[word.length()].push_back(word);

        for (auto &pair : words)
        {
            for (auto &word : pair.second)
                result += word + " ";
        }

        result[0] = toupper(result[0]);
        result.pop_back();

        return result;
    }
};