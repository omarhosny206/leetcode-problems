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

        return bfs(source, destination);
    }

    bool bfs(int &source, int &destination)
    {
        if (source == destination)
            return true;

        queue<int> nodes;
        nodes.push(source);

        while (!nodes.empty())
        {
            int size = nodes.size();

            for (int i = 0; i < size; ++i)
            {
                int current = nodes.front();
                nodes.pop();

                visited[current] = true;

                for (int &vertex : graph[current])
                {
                    if (vertex == destination)
                        return true;

                    if (!visited[vertex])
                        nodes.push(vertex);
                }
            }
        }

        return false;
    }
};