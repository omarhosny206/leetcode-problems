
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
            if (color[i] == -1 && !isBipartite(graph, color, i, 1))
                return false;

        return true;
    }

    bool isBipartite(vector<vector<int>> &graph, vector<int> &color, int source, bool previousColor)
    {
        if (color[source] != -1)
            return color[source] != previousColor;

        color[source] = !previousColor;

        for (int &destination : graph[source])
            if (isBipartite(graph, color, destination, color[source]) == false)
                return false;

        return true;
    }
};