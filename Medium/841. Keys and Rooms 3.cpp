// https://leetcode.com/problems/keys-and-rooms/

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vector<vector<int>> graph = rooms;
        vector<bool> visited(rooms.size());
        stack<int> nodes;

        nodes.push(0);
        visited[0] = true;

        while (!nodes.empty())
        {
            int source = nodes.top();
            nodes.pop();

            for (int &destination : graph[source])
            {
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