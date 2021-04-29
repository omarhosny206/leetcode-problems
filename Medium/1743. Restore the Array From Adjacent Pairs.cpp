// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/

class Solution
{
    vector<int> result;

public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, bool> visited;
        int source;

        for (auto pair : adjacentPairs)
        {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }

        for (auto pair : graph)
        {
            if (pair.second.size() == 1)
            {
                source = pair.first;
                break;
            }
        }

        result.push_back(source);
        DFS(graph, visited, source);

        return result;
    }

    void DFS(unordered_map<int, vector<int>> &graph, unordered_map<int, bool> &visited, int source)
    {
        visited[source] = true;

        for (auto destination : graph[source])
        {
            if (!visited[destination])
            {
                result.push_back(destination);
                DFS(graph, visited, destination);
            }
        }
    }
};