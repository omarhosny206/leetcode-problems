// https://leetcode.com/problems/verifying-an-alien-dictionary/

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        vector<int> rank(26);
        string first = words[0];

        for (int i = 1; i < order.size(); ++i)
            rank[order[i] - 'a'] = i;

        for (int i = 0; i < words.size(); ++i)
        {
            string second = words[i];

            if (!check(rank, first, second))
                return false;

            first = second;
        }

        return true;
    }

    bool check(vector<int> &rank, string &first, string &second)
    {
        int i = 0;
        int j = 0;

        while (i < first.length() && j < second.length() && first[i] == second[j])
        {
            i++;
            j++;
        }

        if (i < first.length() && j == second.length())
            return false;

        if (i < first.length() && j < second.length() && rank[first[i] - 'a'] > rank[second[j] - 'a'])
            return false;

        return true;
    }
};