// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/

class Solution
{
    int result = INT_MAX;

public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> graph(n + 1);
        vector<bool> visited(n + 1);

        for (vector<int> &road : roads)
        {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        dfs(graph, visited, 1);
        return result;
    }

    void dfs(vector<vector<pair<int, int>>> &graph, vector<bool> &visited, int source)
    {
        visited[source] = true;

        for (pair<int, int> &node : graph[source])
        {
            int destination = node.first;
            int distance = node.second;

            result = min(result, distance);

            if (!visited[destination])
                dfs(graph, visited, destination);
        }
    }
};