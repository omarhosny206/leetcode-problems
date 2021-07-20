// https://leetcode.com/problems/time-needed-to-inform-all-employees/

class Solution
{
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        int result = 0;
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; ++i)
            if (manager[i] != -1)
                graph[manager[i]].push_back(i);

        result = DFS(graph, headID, informTime);

        return result;
    }

    int DFS(vector<vector<int>> &graph, int source, vector<int> &informTime)
    {
        int result = 0;

        for (int &destination : graph[source])
            result = max(result, DFS(graph, destination, informTime) + informTime[source]);

        return result;
    }
};