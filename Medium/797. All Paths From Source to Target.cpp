// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution
{
    vector<vector<int>> paths;

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<int> currentPath = {0};
        DFS(graph, 0, currentPath);

        return paths;
    }

    void DFS(vector<vector<int>> &graph, int source, vector<int> &currentPath)
    {

        if (source == graph.size() - 1)
        {
            paths.push_back(currentPath);
            return;
        }

        for (int i = 0; i < graph[source].size(); ++i)
        {
            currentPath.push_back(graph[source][i]);
            DFS(graph, graph[source][i], currentPath);
            currentPath.pop_back();
        }
    }
};