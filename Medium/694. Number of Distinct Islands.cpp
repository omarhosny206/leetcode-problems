// https://leetcode.com/problems/number-of-distinct-islands/

class Solution
{
    unordered_set<string> islands;

public:
    int numberofDistinctIslands(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j)
                if (grid[i][j] == 1)
                    islands.insert(DFS(grid, i, j, "X"));

        return islands.size();
    }

    string DFS(vector<vector<int>> &grid, int i, int j, string currentDirection)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == 0)
            return "O";

        grid[i][j] = 0;

        string UP = DFS(grid, i - 1, j, "U");
        string DOWN = DFS(grid, i + 1, j, "D");
        string LEFT = DFS(grid, i, j - 1, "L");
        string RIGHT = DFS(grid, i, j + 1, "R");

        return currentDirection + UP + DOWN + LEFT + RIGHT;
    }
};