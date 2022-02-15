// https://leetcode.com/problems/minimum-genetic-mutation/

class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        int numMutations = 0;
        vector<char> dnaCode = {'A', 'C', 'G', 'T'};

        queue<string> nodes;
        unordered_set<string> genes;
        unordered_set<string> visited;

        for (string &mutation : bank)
            genes.insert(mutation);

        if (genes.find(end) == genes.end())
            return -1;

        nodes.push(start);
        visited.insert(start);

        while (!nodes.empty())
        {
            numMutations++;
            int size = nodes.size();

            for (int i = 0; i < size; ++i)
            {
                string current = nodes.front();
                nodes.pop();

                for (int j = 0; j < current.length(); ++j)
                {
                    string temp = current;

                    for (int k = 0; k < dnaCode.size(); ++k)
                    {
                        temp[j] = dnaCode[k];

                        if (temp == current || visited.find(temp) != visited.end())
                            continue;

                        if (temp == end)
                            return numMutations;

                        if (genes.find(temp) != genes.end())
                        {
                            nodes.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
            }
        }

        return -1;
    }
};