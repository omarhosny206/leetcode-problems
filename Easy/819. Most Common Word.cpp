// https://leetcode.com/problems/most-common-word/

class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {

        unordered_set<string> set(banned.begin(), banned.end());
        unordered_map<string, int> mapping;

        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);

        for (int i = 0; i < paragraph.size(); i++)
            if (paragraph[i] < 'a' or paragraph[i] > 'z')
                paragraph[i] = ' ';

        istringstream ss(paragraph);
        string word;
        while (ss >> word)
        {
            if (set.find(word) == set.end())
                mapping[word]++;
        }

        int max = 0;

        for (auto p : mapping)
        {
            if (p.second > max)
            {
                max = p.second;
                word = p.first;
            }
        }
        return word;
    }
};