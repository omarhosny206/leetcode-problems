// https://leetcode.com/problems/count-sub-islands/

class Solution
{
    bool isSubIsland = true;

public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int result = 0;

        for (int i = 0; i < grid2.size(); ++i)
        {
            for (int j = 0; j < grid2[i].size(); ++j)
            {
                if (grid2[i][j] == 1)
                {
                    isSubIsland = true;

                    DFS(grid1, grid2, i, j);

                    if (isSubIsland)
                        result++;
                }
            }
        }

        return result;
    }

    void DFS(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j)
    {
        if (i < 0 || i >= grid2.size() || j < 0 || j >= grid2[i].size() || grid2[i][j] == 0)
            return;

        if (grid1[i][j] == 0)
            isSubIsland = false;

        grid2[i][j] = 0;
        DFS(grid1, grid2, i + 1, j);
        DFS(grid1, grid2, i - 1, j);
        DFS(grid1, grid2, i, j + 1);
        DFS(grid1, grid2, i, j - 1);
    }
};