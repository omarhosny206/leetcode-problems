// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string first = "";
        string second = "";

        for (string word : word1)
            for (char letter : word)
                first += letter;

        for (string word : word2)
            for (char letter : word)
                second += letter;

        return first == second;
    }
};