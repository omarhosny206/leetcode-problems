// https://leetcode.com/problems/redundant-connection/

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        vector<int> parent(edges.size() + 1, -1);

        for (auto edge : edges)
        {
            int sourceParent = Find(parent, edge[0]);
            int destinationParent = Find(parent, edge[1]);

            if (sourceParent == destinationParent)
                return edge;

            Union(parent, sourceParent, destinationParent);
        }

        return {};
    }

    int Find(vector<int> &parent, int source)
    {
        if (parent[source] == -1)
            return source;

        return Find(parent, parent[source]);
    }

    void Union(vector<int> &parent, int source, int destination)
    {
        parent[destination] = source;
        return;
    }
};