// https://leetcode.com/problems/rearrange-words-in-a-sentence/

class Solution
{
public:
    string arrangeWords(string text)
    {
        string result = "";
        vector<string> words;
        string word = "";

        text[0] = tolower(text[0]);

        for (int i = 0; i < text.length(); ++i)
        {
            if (text[i] == ' ')
            {
                words.push_back(word);
                word = "";
            }

            else
                word += text[i];
        }

        words.push_back(word);

        stable_sort(words.begin(), words.end(), [](const string &first, const string &second)
                    { return (first.length() < second.length()); });

        for (string &word : words)
            result += word + " ";

        result[0] = toupper(result[0]);
        result.pop_back();

        return result;
    }
};