// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution
{
    vector<vector<int>> paths;

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<int> currentPath = {0};
        dfs(graph, 0, currentPath);

        return paths;
    }

    void dfs(vector<vector<int>> &graph, int source, vector<int> &currentPath)
    {
        if (source == graph.size() - 1)
        {
            paths.push_back(currentPath);
            return;
        }

        for (int &destination : graph[source])
        {
            currentPath.push_back(destination);
            dfs(graph, destination, currentPath);
        }

        currentPath.pop_back();
    }
};