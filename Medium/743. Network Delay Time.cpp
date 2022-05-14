// https://leetcode.com/problems/network-delay-time/

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        int result = INT_MIN;
        vector<vector<pair<int, int>>> graph(n + 1);

        for (int i = 0; i < times.size(); ++i)
        {
            int source = times[i][0];
            int destination = times[i][1];
            int time = times[i][2];

            graph[source].push_back({destination, time});
        }

        vector<int> distances = getShortestPath(graph, k);

        for (int i = 1; i <= n; i++)
        {
            if (distances[i] == INT_MAX)
                return -1;

            result = max(result, distances[i]);
        }

        return result;
    }

    vector<int> getShortestPath(vector<vector<pair<int, int>>> &graph, int source)
    {
        vector<int> distances(graph.size(), INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> vertices;

        distances[source] = 0;
        vertices.push({0, source});

        while (!vertices.empty())
        {
            int source = vertices.top().second;
            vertices.pop();

            for (auto &edge : graph[source])
            {
                int destination = edge.first;
                int time = edge.second;

                if (distances[source] + time < distances[destination])
                {
                    distances[destination] = distances[source] + time;
                    vertices.push({distances[destination], destination});
                }
            }
        }

        return distances;
    }
};