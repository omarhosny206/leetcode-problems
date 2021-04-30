// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

class Solution
{
public:
    int countComponents(int n, vector<vector<int>> &edges)
    {
        int result = 0;
        vector<vector<int>> graph(n);
        vector<int> visited(n);

        for (auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; ++i)
        {
            if (visited[i] == 0)
            {
                DFS(graph, visited, i);
                result++;
            }
        }

        return result;
    }

    void DFS(vector<vector<int>> &graph, vector<int> &visited, int source)
    {
        visited[source] = 1;

        for (int destination : graph[source])
            if (visited[destination] == 0)
                DFS(graph, visited, destination);
    }
};