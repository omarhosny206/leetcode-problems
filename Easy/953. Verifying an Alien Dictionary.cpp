class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        vector<int> rank(26);

        for (int i = 0; i < order.size(); ++i)
            rank[order[i] - 'a'] = i;

        for (int i = 0; i < words.size(); ++i)
            for (int j = i + 1; j < words.size(); ++j)
                if (!check(rank, words[i], words[j]))
                    return false;

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