// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

class Solution
{
public:
    int countComponents(int n, vector<vector<int>> &edges)
    {
        int result = n;
        vector<int> parent(n, -1);

        for (int i = 0; i < edges.size(); ++i)
        {
            int sourceParent = Find(parent, edges[i][0]);
            int destinationParent = Find(parent, edges[i][1]);

            if (sourceParent != destinationParent)
            {
                Union(parent, sourceParent, destinationParent);
                result--;
            }
        }
        return result;
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