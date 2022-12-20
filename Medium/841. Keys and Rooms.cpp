// https://leetcode.com/problems/keys-and-rooms/

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vector<vector<int>> graph = rooms;
        vector<bool> visited(rooms.size());

        dfs(graph, visited, 0);

        for (const bool &value : visited)
            if (value == false)
                return false;

        return true;
    }

    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int source)
    {
        visited[source] = true;

        for (int destination : graph[source])
            if (!visited[destination])
                dfs(graph, visited, destination);
    }
};