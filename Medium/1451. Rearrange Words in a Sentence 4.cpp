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
        stringstream textWords(text);

        while (textWords >> word)
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