// https://leetcode.com/problems/sum-of-distances-in-tree/

class Solution
{
    vector<int> result;

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        result = vector<int>(n);
        vector<vector<int>> graph(n);
        vector<int> depth(n);

        for (vector<int> &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n);
        dfs(graph, visited, depth, 0, 0);

        for (int &value : depth)
            result[0] += value;

        fill(visited.begin(), visited.end(), false);
        vector<int> numNodes(n);
        countNumNodes(graph, visited, numNodes, 0);

        fill(visited.begin(), visited.end(), false);
        countDistances(graph, visited, numNodes, 0, result[0] + numNodes[0]);

        return result;
    }

    void countDistances(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &numNodes, int source, int parentDistance)
    {
        visited[source] = true;
        result[source] = parentDistance - numNodes[source] + (graph.size() - numNodes[source]);

        for (int &destination : graph[source])
            if (!visited[destination])
                countDistances(graph, visited, numNodes, destination, result[source]);
    }

    int countNumNodes(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &numNodes, int source)
    {
        int result = 0;

        if (visited[source])
            return 0;

        visited[source] = true;

        for (int &destination : graph[source])
            result += countNumNodes(graph, visited, numNodes, destination);

        numNodes[source] = result + 1;
        return numNodes[source];
    }

    void dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &depth, int source, int currentDepth)
    {
        visited[source] = true;
        depth[source] = currentDepth;

        for (int &destination : graph[source])
            if (!visited[destination])
                dfs(graph, visited, depth, destination, currentDepth + 1);
    }
};