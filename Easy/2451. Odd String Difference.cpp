// https://leetcode.com/problems/odd-string-difference/

class Solution
{
public:
    string oddString(vector<string> &words)
    {
        map<vector<int>, int> freq;
        map<vector<int>, int> seen;
        int position = 0;

        for (string &word : words)
        {
            vector<int> current;

            int i = 0;

            while (i < word.length() - 1)
            {
                int value = (word[i + 1] - 'a') - (word[i] - 'a');
                current.push_back(value);
                i++;
            }

            freq[current]++;
            seen[current] = position++;
        }

        for (auto &pair : freq)
            if (pair.second == 1)
                return words[seen[pair.first]];

        return "";
    }
};