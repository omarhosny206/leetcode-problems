// https://leetcode.com/problems/find-if-path-exists-in-graph/

class Solution
{
    bool isConnected = false;
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

        dfs(source, destination);
        return isConnected;
    }

    void dfs(int &source, int &destination)
    {
        if (source == destination)
        {
            isConnected = true;
            return;
        }

        if (visited[source])
            return;

        visited[source] = true;

        for (int &vertex : graph[source])
            if (!visited[vertex])
                dfs(vertex, destination);
    }
};