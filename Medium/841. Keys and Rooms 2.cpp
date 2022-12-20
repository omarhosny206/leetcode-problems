// https://leetcode.com/problems/keys-and-rooms/

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        return bfs(rooms);
    }

    bool bfs(vector<vector<int>> &graph)
    {
        queue<int> nodes;
        vector<bool> visited(graph.size());

        nodes.push(0);
        visited[0] = true;

        while (!nodes.empty())
        {
            int size = nodes.size();
            int source = nodes.front();
            nodes.pop();

            for (int i = 0; i < graph[source].size(); ++i)
            {
                int destination = graph[source][i];

                if (!visited[destination])
                {
                    visited[destination] = true;
                    nodes.push(destination);
                }
            }
        }

        for (const bool &value : visited)
            if (value == false)
                return false;

        return true;
    }
};