// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/

class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        stringstream s(sentence);
        string word;
        int counter = 1;

        while (s >> word)
        {
            if (word.substr(0, searchWord.size()) == searchWord)
                return counter;

            counter += 1;
        }

        return -1;
    }
};