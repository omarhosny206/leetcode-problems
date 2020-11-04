// https://leetcode.com/problems/shortest-completing-word/

class Solution
{
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        int letter[26] = {0};

        for (char c : licensePlate)
        {
            if (isalpha(c))
                letter[tolower(c) - 'a']++;
        }

        string result;
        int result_length = INT_MAX;

        for (string word : words)
        {

            int wordLetter[26] = {0};
            bool isCompletingWord = true;
            for (char c : word)
                wordLetter[c - 'a']++;

            for (int i = 0; i < 26; i++)
            {
                if (letter[i] > wordLetter[i])
                    isCompletingWord = false;
            }

            if (isCompletingWord && word.length() < result_length)
            {
                result = word;
                result_length = word.length();
            }
        }

        return result;
    }
};