// https://leetcode.com/problems/camelcase-matching/

class Solution
{
public:
    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        vector<bool> result;

        for (string &query : queries)
            result.push_back(canForm(pattern, query));

        return result;
    }

    bool canForm(string &first, string &second)
    {
        int i = 0;
        int j = 0;

        while (i < first.length() && j < second.length())
        {
            if (isupper(second[j]) && first[i] != second[j])
                return false;

            if (first[i] == second[j])
                i++;

            j++;
        }

        while (j < second.length())
        {
            if (isupper(second[j]))
                return false;
            j++;
        }

        return i == first.length();
    }
};