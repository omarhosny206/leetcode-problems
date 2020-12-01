// https://leetcode.com/problems/keys-and-rooms/

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vector<bool> seen(rooms.size(), false);

        DFS(0, rooms, seen);

        for (bool visited : seen)
            if (!visited)
                return false;

        return true;
    }

    void DFS(int room, vector<vector<int>> &rooms, vector<bool> &seen)
    {
        seen[room] = true;
        for (int i = 0; i < rooms[room].size(); ++i)
            if (!seen[rooms[room][i]])
                DFS(rooms[room][i], rooms, seen);
    }
};