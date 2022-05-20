// https://leetcode.com/problems/critical-connections-in-a-network/

class Solution
{
public:
    vector<vector<int>> result;
    vector<vector<int>> graph;
    vector<int> visited;
    vector<int> low;
    vector<int> tin;
    int time;

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        graph = vector<vector<int>>(n);
        visited = vector<int>(n);
        low = vector<int>(n);
        tin = vector<int>(n);
        time = 1;

        for (vector<int> &edge : connections)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1);
        return result;
    }

    void dfs(int source, int parent)
    {
        visited[source] = true;
        low[source] = time;
        tin[source] = time;
        time++;

        for (int &destination : graph[source])
        {
            if (destination == parent)
                continue;

            if (visited[destination])
                low[source] = min(low[source], tin[destination]);

            else
            {
                dfs(destination, source);

                if (tin[source] < low[destination])
                    result.push_back({source, destination});

                else
                    low[source] = min(low[source], low[destination]);
            }
        }
    }
};