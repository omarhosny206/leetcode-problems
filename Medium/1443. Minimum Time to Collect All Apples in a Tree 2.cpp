
class Solution
{
public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        int result = 0;
        vector<vector<int>> graph(n);
        vector<bool> visited(n);

        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        result = dfs(graph, hasApple, visited, 0);
        return result * 2;
    }

    int dfs(vector<vector<int>> &graph, vector<bool> &hasApple, vector<bool> &visited, int source)
    {
        int result = 0;
        visited[source] = true;

        for (int &destination : graph[source])
            if (!visited[destination])
                result += dfs(graph, hasApple, visited, destination);

        if (source == 0)
            return result;

        if (result == 0)
            return hasApple[source];

        return result + 1;
    }
};