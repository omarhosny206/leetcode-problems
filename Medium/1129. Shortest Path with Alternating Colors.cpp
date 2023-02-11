
class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<vector<pair<int, int>>> graph(n);

        for (vector<int> &redEdge : redEdges)
            graph[redEdge[0]].push_back({redEdge[1], 0});

        for (vector<int> &blueEdge : blueEdges)
            graph[blueEdge[0]].push_back({blueEdge[1], 1});

        return bfs(graph);
    }

    vector<int> bfs(vector<vector<pair<int, int>>> &graph)
    {
        vector<int> result(graph.size(), -1);
        queue<vector<int>> nodes;
        vector<vector<bool>> visited(graph.size(), vector<bool>(2));

        nodes.push({0, 0, -1});
        visited[0][0] = true;
        visited[0][1] = true;
        result[0] = 0;

        while (!nodes.empty())
        {
            int size = nodes.size();

            for (int i = 0; i < size; ++i)
            {
                vector<int> node = nodes.front();
                nodes.pop();

                int source = node[0];
                int sourceDistance = node[1];
                int sourceColor = node[2];

                for (pair<int, int> &edge : graph[source])
                {
                    int destination = edge.first;
                    int destinationColor = edge.second;

                    if (sourceColor == destinationColor)
                        continue;

                    if (!visited[destination][destinationColor])
                    {
                        visited[destination][destinationColor] = true;

                        if (result[destination] == -1)
                            result[destination] = sourceDistance + 1;

                        nodes.push({destination, sourceDistance + 1, destinationColor});
                    }
                }
            }
        }

        return result;
    }
};