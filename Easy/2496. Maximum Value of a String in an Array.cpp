// https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/

class Solution
{
public:
    int maximumValue(vector<string> &strs)
    {
        int result = INT_MIN;

        for (string &word : strs)
        {
            if (hasOnlyLetters(word))
                result = max(result, (int)word.length());

            else
            {
                int value = stoi(word);
                result = max(result, value);
            }
        }

        return result;
    }

    bool hasOnlyLetters(string &word)
    {
        for (char &c : word)
            if (!isdigit(c))
                return true;

        return false;
    }
};