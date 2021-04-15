// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        int counter = 0;
        vector<bool> visited(n);
        set<pair<int, int>> edges;
        unordered_map<int, vector<int>> graph;

        for (vector<int> edge : connections)
        {
            edges.insert({edge[0], edge[1]});
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        DFS(0, visited, edges, graph, counter);
        return counter;
    }

    void DFS(int source, vector<bool> &visited, set<pair<int, int>> &edges, unordered_map<int, vector<int>> &graph, int &counter)
    {

        visited[source] = true;

        for (auto destination : graph[source])
        {
            if (visited[destination] == false)
            {
                if (edges.find({source, destination}) != edges.end())
                    counter++;
                DFS(destination, visited, edges, graph, counter);
            }
        }
    }
};