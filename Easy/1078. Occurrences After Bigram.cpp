// https://leetcode.com/problems/occurrences-after-bigram/

class Solution
{
public:
    vector<string> findOcurrences(string text, string first, string second)
    {
        vector<string> answer;
        stringstream statement(text);
        string word = "";
        vector<string> words;

        while (statement >> word)
            words.push_back(word);

        for (int i = 0; i < words.size() - 2; i++)
            if (words[i] == first && words[i + 1] == second)
                answer.push_back(words[i + 2]);

        return answer;
    }
};