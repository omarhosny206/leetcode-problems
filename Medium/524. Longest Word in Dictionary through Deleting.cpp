// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/

class Solution
{
public:
    string findLongestWord(string s, vector<string> &dictionary)
    {
        string result = "";
        sort(dictionary.begin(), dictionary.end());

        for (string &word : dictionary)
            if (canForm(word, s))
                if (result.length() < word.length())
                    result = word;

        return result;
    }

    bool canForm(string &first, string &second)
    {
        int i = 0;
        int j = 0;

        while (i < first.length() && j < second.length())
        {
            if (first[i] == second[j])
                i++;
            j++;
        }

        return i == first.length();
    }
};