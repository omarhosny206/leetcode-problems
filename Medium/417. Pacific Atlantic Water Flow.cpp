// https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        vector<vector<int>> result;

        int rows = heights.size();
        int columns = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(columns));
        vector<vector<bool>> atlantic(rows, vector<bool>(columns));

        for (int i = 0; i < rows; ++i)
        {
            dfs(heights, pacific, i, 0, heights[i][0]);
            dfs(heights, atlantic, i, columns - 1, heights[i][columns - 1]);
        }

        for (int j = 0; j < columns; ++j)
        {
            dfs(heights, pacific, 0, j, heights[0][j]);
            dfs(heights, atlantic, rows - 1, j, heights[rows - 1][j]);
        }

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
            }
        }

        return result;
    }

    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &ocean, int i, int j, int previousHeight)
    {
        if (i < 0 || i >= heights.size() || j < 0 || j >= heights[i].size() || ocean[i][j] == true || heights[i][j] < previousHeight)
            return;

        ocean[i][j] = true;

        dfs(heights, ocean, i + 1, j, heights[i][j]);
        dfs(heights, ocean, i - 1, j, heights[i][j]);
        dfs(heights, ocean, i, j + 1, heights[i][j]);
        dfs(heights, ocean, i, j - 1, heights[i][j]);
    }
};