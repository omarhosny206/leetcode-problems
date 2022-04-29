// https://leetcode.com/problems/is-graph-bipartite/

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> color(graph.size(), -1);

        for (int i = 0; i < graph.size(); ++i)
            if (color[i] == -1 && !dfs(graph, color, i, 0))
                return false;

        return true;
    }

    bool dfs(vector<vector<int>> &graph, vector<int> &color, int source, int previousColor)
    {
        if (color[source] != -1)
            return color[source] != previousColor;

        color[source] = !previousColor;

        for (int &destination : graph[source])
            if (!dfs(graph, color, destination, color[source]))
                return false;

        return true;
    }
};