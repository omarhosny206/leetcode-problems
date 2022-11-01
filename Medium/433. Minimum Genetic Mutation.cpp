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
            int size = nodes.size();

            for (int i = 0; i < size; ++i)
            {
                string currentGene = nodes.front();
                nodes.pop();

                if (currentGene == end)
                    return numMutations;

                for (int j = 0; j < currentGene.length(); ++j)
                {
                    string temp = currentGene;

                    for (int k = 0; k < dnaCode.size(); ++k)
                    {
                        temp[j] = dnaCode[k];

                        if (temp == currentGene || visited.find(temp) != visited.end())
                            continue;

                        if (genes.find(temp) != genes.end())
                        {
                            nodes.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
            }

            numMutations++;
        }

        return -1;
    }
};