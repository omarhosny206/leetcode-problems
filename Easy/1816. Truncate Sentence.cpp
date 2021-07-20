// https://leetcode.com/problems/truncate-sentence/

class Solution
{
public:
    string truncateSentence(string s, int k)
    {
        string result = getSentence(s, k);
        return result;
    }

    string getSentence(string &sentence, int k)
    {
        string result = "";
        string word = "";
        int counter = 0;
        int i = 0;

        while (i < sentence.length() && counter < k)
        {
            if (sentence[i] == ' ')
            {
                result += word + " ";
                word = "";
                counter++;
            }

            else
                word += sentence[i];

            i++;
        }

        if (counter == k)
            result.pop_back();

        if (counter < k)
            result += word;

        return result;
    }
};