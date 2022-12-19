// https://leetcode.com/problems/find-if-path-exists-in-graph/

class Solution
{
    vector<vector<int>> graph;
    vector<bool> visited;

public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        graph = vector<vector<int>>(n);
        visited = vector<bool>(n);

        for (vector<int> &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return dfs(source, destination);
    }

    bool dfs(int &source, int &destination)
    {
        bool result = false;

        if (source == destination)
            return true;

        visited[source] = true;

        for (int &vertex : graph[source])
            if (!visited[vertex])
                result = result || dfs(vertex, destination);

        return result;
    }
};