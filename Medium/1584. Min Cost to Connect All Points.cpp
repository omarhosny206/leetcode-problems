
class Graph
{
private:
    vector<vector<pair<int, int>>> graph;
    vector<bool> visited;
    vector<int> distance;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> vertices;

public:
    Graph(vector<vector<pair<int, int>>> &data)
    {
        this->graph = data;
        this->visited = vector<bool>(graph.size());
        this->distance = vector<int>(graph.size(), INT_MAX);
    }

    void minimumSpanningTree(int source)
    {
        distance[source] = 0;
        vertices.push({distance[source], source});

        while (!vertices.empty())
        {
            source = vertices.top().second;
            vertices.pop();

            if (visited[source])
                continue;

            visited[source] = true;

            for (pair<int, int> &edge : graph[source])
            {
                int destination = edge.first;
                int edgeDistance = edge.second;

                if (!visited[destination] && edgeDistance < distance[destination])
                {
                    distance[destination] = edgeDistance;
                    vertices.push({distance[destination], destination});
                }
            }
        }
    }

    int countDistances()
    {
        int result = 0;

        for (int &value : distance)
            result += value;

        return result;
    }
};

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        Graph *graph = nullptr;
        vector<vector<pair<int, int>>> data(points.size());

        for (int i = 0; i < points.size(); ++i)
        {
            for (int j = i + 1; j < points.size(); ++j)
            {
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                data[i].push_back({j, distance});
                data[j].push_back({i, distance});
            }
        }

        graph = new Graph(data);

        graph->minimumSpanningTree(0);

        return graph->countDistances();
    }
};