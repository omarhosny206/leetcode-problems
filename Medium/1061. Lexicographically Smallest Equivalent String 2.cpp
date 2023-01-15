// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/

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

    void Union(int first, int second)
    {
        first = find(first);
        second = find(second);

        if (first != second)
            parent[max(first, second)] = min(first, second);
    }
};

class Solution
{
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        DSU *dsu = new DSU();

        for (int i = 0; i < s1.size(); ++i)
            dsu->Union(s1[i] - 'a', s2[i] - 'a');

        for (int i = 0; i < baseStr.size(); ++i)
            baseStr[i] = (dsu->find(baseStr[i] - 'a')) + 'a';

        return baseStr;
    }
};