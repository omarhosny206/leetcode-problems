// https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/

class Solution
{
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord)
    {
        int first = getValue(firstWord);
        int second = getValue(secondWord);
        int target = getValue(targetWord);
        return target == first + second;
    }

    int getValue(string &word)
    {
        int result = 0;

        for (int i = 0; i < word.length(); ++i)
            result = result * 10 + (word[i] - 'a');

        return result;
    }
};