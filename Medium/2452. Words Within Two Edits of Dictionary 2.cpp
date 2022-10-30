// https://leetcode.com/problems/words-within-two-edits-of-dictionary/

class Solution
{
public:
    vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary)
    {
        vector<string> result;
        const int MAX_EDIT_ATTEMPTS = 2;

        for (int i = 0; i < queries.size(); ++i)
        {
            for (int j = 0; j < dictionary.size(); ++j)
            {
                if (canForm(queries[i], dictionary[j], MAX_EDIT_ATTEMPTS))
                {
                    result.push_back(queries[i]);
                    break;
                }
            }
        }

        return result;
    }

    bool canForm(string &first, string &second, int editAttemps)
    {
        int i = 0;
        int j = 0;

        while (i < first.length())
        {
            if (first[i] != second[j])
                editAttemps--;

            if (editAttemps < 0)
                return false;

            i++;
            j++;
        }

        return true;
    }
};