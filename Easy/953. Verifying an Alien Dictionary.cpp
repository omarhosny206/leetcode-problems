// https://leetcode.com/problems/verifying-an-alien-dictionary/

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        if (words.size() == 1)
            return true;

        int rank[26];
        for (int i = 0; i < order.size(); ++i)
            rank[order[i] - 'a'] = i;

        for (int i = 1; i < words.size(); ++i)
        {
            string current = words[i];
            string previous = words[i - 1];
            int currentLength = current.length();
            int previousLength = previous.length();
            int size = min(previousLength, currentLength);
            int j = 0;

            while (j < size && current[j] == previous[j])
                j++;

            if (j == size && previousLength > currentLength)
                return false;

            if (j < size && rank[previous[j] - 'a'] > rank[current[j] - 'a'])
                return false;
        }

        return true;
    }
};