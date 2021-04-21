// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (n > connections.size() + 1)
            return -1;

        int connectedComponents = 0;
        vector<vector<int>> graph(n);
        vector<bool> visited(n);

        for (vector<int> connection : connections)
        {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }

        for (int i = 0; i < n; ++i)
        {
            if (visited[i] == false)
            {
                connectedComponents++;
                DFS(graph, visited, i);
            }
        }

        return connectedComponents - 1;
    }

    void DFS(vector<vector<int>> &graph, vector<bool> &visited, int source)
    {
        if (visited[source] == true)
            return;

        visited[source] = true;
        for (int destination : graph[source])
            DFS(graph, visited, destination);
    }
};