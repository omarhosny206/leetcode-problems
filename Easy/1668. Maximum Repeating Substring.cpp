// https://leetcode.com/problems/maximum-repeating-substring/

class Solution
{
public:
    int maxRepeating(string sequence, string word)
    {
        int resCount = 0;
        string currentWord = word;
        int numWords = sequence.length() / word.length();

        while (sequence.find(currentWord) != string::npos)
        {
            currentWord += word;
            resCount++;
        }

        return resCount;
    }
};