class Solution
{
    int result = 1;

public:
    int longestPath(vector<int> &parent, string s)
    {
        vector<vector<int>> graph(parent.size());
        vector<bool> visited(parent.size());

        for (int i = 1; i < parent.size(); ++i)
        {
            graph[parent[i]].push_back(i);
            graph[i].push_back(parent[i]);
        }

        for (int i = 0; i < graph.size(); ++i)
            if (!visited[i])
                dfs(graph, visited, s, i);

        return result;
    }

    int dfs(vector<vector<int>> &graph, vector<bool> &visited, string &s, int source)
    {
        int firstMax = 0;
        int secondMax = 0;

        visited[source] = true;

        for (int &destination : graph[source])
        {
            if (!visited[destination] && s[source] != s[destination])
            {
                int value = dfs(graph, visited, s, destination);

                if (value > firstMax)
                {
                    secondMax = firstMax;
                    firstMax = value;
                }

                else if (value > secondMax)
                    secondMax = value;
            }
        }

        result = max(result, firstMax + secondMax + 1);
        return firstMax + 1;
    }
};