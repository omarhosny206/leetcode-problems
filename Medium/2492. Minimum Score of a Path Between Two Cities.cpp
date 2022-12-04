// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/

class Solution
{
public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        int result = INT_MAX;

        vector<vector<int>> graph(n + 1);
        vector<bool> visited(n + 1);
        vector<int> minValue(n + 1, INT_MAX);

        for (vector<int> &road : roads)
        {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
            minValue[road[0]] = min(minValue[road[0]], road[2]);
            minValue[road[1]] = min(minValue[road[1]], road[2]);
        }

        dfs(graph, visited, 1);

        for (int i = 1; i <= n; ++i)
            if (visited[i])
                result = min(result, minValue[i]);

        return result;
    }

    bool dfs(vector<vector<int>> &graph, vector<bool> &visited, int source)
    {
        visited[source] = true;

        for (int &destination : graph[source])
            if (!visited[destination] && dfs(graph, visited, destination))
                return true;

        return false;
    }
};