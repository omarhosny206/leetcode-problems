class DSU
{
    vector<int> parent;

public:
    DSU()
    {
        parent = vector<int>(26, -1);
    }

    int find(int node)
    {
        if (parent[node] == -1)
            return node;

        parent[node] = find(parent[node]);
        return parent[node];
    }

    void Union(int source, int destination)
    {
        parent[destination] = source;
    }
};

class Solution
{
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        DSU *dsu = new DSU();

        for (int i = 0; i < s1.size(); ++i)
        {
            int firstParent = dsu->find(s1[i] - 'a');
            int secondParent = dsu->find(s2[i] - 'a');

            if (firstParent != secondParent)
                dsu->Union(min(firstParent, secondParent), max(firstParent, secondParent));
        }

        for (int i = 0; i < baseStr.size(); ++i)
            baseStr[i] = (dsu->find(baseStr[i] - 'a')) + 'a';

        return baseStr;
    }
};