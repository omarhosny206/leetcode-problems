// https://leetcode.com/problems/word-ladder/

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int numTransformations = 0;

        queue<string> nodes;
        unordered_set<string> words;
        unordered_set<string> visited;

        for (string &word : wordList)
            words.insert(word);

        if (words.find(endWord) == words.end())
            return 0;

        nodes.push(beginWord);
        visited.insert(beginWord);

        while (!nodes.empty())
        {
            numTransformations++;
            int size = nodes.size();

            for (int i = 0; i < size; ++i)
            {
                string current = nodes.front();
                nodes.pop();

                for (int j = 0; j < current.length(); ++j)
                {
                    string temp = current;

                    for (int k = 0; k < 26; ++k)
                    {
                        temp[j] = k + 'a';

                        if (temp == current || visited.find(temp) != visited.end())
                            continue;

                        if (temp == endWord)
                            return numTransformations + 1;

                        if (words.find(temp) != words.end())
                        {
                            nodes.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
            }
        }

        return 0;
    }
};