// https://leetcode.com/problems/is-graph-bipartite/

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> color(graph.size(), -1);

        for (int i = 0; i < graph.size(); ++i)
            if (color[i] == -1 && !bfs(graph, color, i))
                return false;

        return true;
    }

    bool bfs(vector<vector<int>> &graph, vector<int> &color, int source)
    {
        queue<int> nodes;
        nodes.push(source);
        color[source] = 0;

        while (!nodes.empty())
        {
            int current = nodes.front();
            nodes.pop();

            for (int &destination : graph[current])
            {
                if (color[destination] == -1)
                {
                    color[destination] = !color[current];
                    nodes.push(destination);
                }

                else if (color[destination] == color[current])
                    return false;
            }
        }

        return true;
    }
};