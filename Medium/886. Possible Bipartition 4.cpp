// https://leetcode.com/problems/possible-bipartition/

class Solution
{
public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<vector<int>> graph(n + 1);
        vector<int> color(n + 1, -1);

        for (vector<int> &dislike : dislikes)
        {
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }

        for (int i = 1; i <= n; ++i)
            if (color[i] == -1 && !isBipartite(graph, color, i))
                return false;

        return true;
    }

    bool isBipartite(vector<vector<int>> &graph, vector<int> &color, int source)
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