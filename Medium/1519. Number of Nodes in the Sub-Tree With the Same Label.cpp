// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/

class Solution
{
    vector<int> result;

public:
    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        result = vector<int>(n);
        vector<vector<int>> graph(n);
        vector<bool> visited(n);

        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        dfs(graph, visited, labels, 0);
        return result;
    }

    vector<int> dfs(vector<vector<int>> &graph, vector<bool> &visited, string &labels, int source)
    {
        vector<int> freq(26);
        visited[source] = true;

        freq[labels[source] - 'a'] = 1;

        for (int &destination : graph[source])
        {
            if (!visited[destination])
            {
                vector<int> destinationFreq = dfs(graph, visited, labels, destination);

                for (int i = 0; i < freq.size(); ++i)
                    freq[i] += destinationFreq[i];
            }
        }

        result[source] = freq[labels[source] - 'a'];
        return freq;
    }
};