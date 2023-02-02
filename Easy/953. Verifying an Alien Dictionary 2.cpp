class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        unordered_map<char, int> rank;
        string first = words[0];

        for (int i = 1; i < order.size(); ++i)
            rank[order[i]] = i;

        for (int i = 0; i < words.size(); ++i)
        {
            string second = words[i];

            if (!check(rank, first, second))
                return false;

            first = second;
        }

        return true;
    }

    bool check(unordered_map<char, int> &rank, string &first, string &second)
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

        if (i < first.length() && j < second.length() && rank[first[i]] > rank[second[j]])
            return false;

        return true;
    }
};