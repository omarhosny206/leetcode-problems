// https://leetcode.com/problems/check-if-the-sentence-is-pangram/

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        unordered_set<char> letters;

        if (sentence.length() < 26)
            return false;

        for (char &c : sentence)
            letters.insert(c);

        return letters.size() == 26;
    }
};