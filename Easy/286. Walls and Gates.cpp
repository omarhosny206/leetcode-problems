// https://leetcode.com/problems/walls-and-gates/

class Solution
{
public:
    void wallsAndGates(vector<vector<int>> &rooms)
    {
        queue<pair<int, int>> cells;

        for (int i = 0; i < rooms.size(); ++i)
            for (int j = 0; j < rooms[i].size(); ++j)
                if (rooms[i][j] == 0)
                    cells.push({i, j});

        BFS(rooms, cells);
    }

    void BFS(vector<vector<int>> &rooms, queue<pair<int, int>> &cells)
    {
        int directions[] = {-1, 0, 1, 0, -1};

        while (!cells.empty())
        {
            int i = cells.front().first;
            int j = cells.front().second;
            cells.pop();

            for (int k = 0; k < 4; ++k)
            {
                if (checkBoundaries(rooms, i + directions[k], j + directions[k + 1]))
                {
                    rooms[i + directions[k]][j + directions[k + 1]] = rooms[i][j] + 1;
                    cells.push({i + directions[k], j + directions[k + 1]});
                }
            }
        }
    }

    bool checkBoundaries(vector<vector<int>> &rooms, int i, int j)
    {
        if (i < 0 || i >= rooms.size() || j < 0 || j >= rooms[i].size() || rooms[i][j] != INT_MAX)
            return false;

        return true;
    }
};