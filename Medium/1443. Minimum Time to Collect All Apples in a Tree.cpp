// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

class Solution
{
public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        int result = 0;
        vector<vector<int>> graph(n);
        vector<bool> visited(n);

        visited[0] = true;

        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (int &destination : graph[0])
            result += DFS(graph, visited, hasApple, destination);

        return result;
    }

    int DFS(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &hasApple, int source)
    {
        int result = 0;
        visited[source] = true;

        for (int &destination : graph[source])
            if (!visited[destination])
                result += DFS(graph, visited, hasApple, destination);

        if (result > 0 || hasApple[source])
            return result + 2;

        return result;
    }
};