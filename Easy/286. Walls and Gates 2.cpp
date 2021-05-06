// https://leetcode.com/problems/walls-and-gates/

class Solution
{
public:
    void wallsAndGates(vector<vector<int>> &rooms)
    {

        for (int i = 0; i < rooms.size(); ++i)
            for (int j = 0; j < rooms[i].size(); ++j)
                if (rooms[i][j] == 0)
                    DFS(rooms, 0, i, j);
    }

    void DFS(vector<vector<int>> &rooms, int counter, int i, int j)
    {
        if (i < 0 || i >= rooms.size() || j < 0 || j >= rooms[i].size() || rooms[i][j] < counter)
            return;

        rooms[i][j] = counter;
        DFS(rooms, counter + 1, i + 1, j);
        DFS(rooms, counter + 1, i - 1, j);
        DFS(rooms, counter + 1, i, j + 1);
        DFS(rooms, counter + 1, i, j - 1);
    }
};