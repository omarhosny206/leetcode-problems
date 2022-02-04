// https://leetcode.com/problems/find-all-groups-of-farmland/

class Solution
{
    int minXCoordinate;
    int minYCoordinate;
    int maxXCoordinate;
    int maxYCoordinate;

public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        vector<vector<int>> result;

        for (int i = 0; i < land.size(); ++i)
        {
            for (int j = 0; j < land[0].size(); ++j)
            {
                if (land[i][j] == 1)
                {
                    resetCoordinates();
                    dfs(land, i, j);
                    result.push_back({minXCoordinate, minYCoordinate, maxXCoordinate, maxYCoordinate});
                }
            }
        }

        return result;
    }

    void dfs(vector<vector<int>> &land, int i, int j)
    {
        if (i < 0 || i >= land.size() || j < 0 || j >= land[0].size() || land[i][j] == 0)
            return;

        minXCoordinate = min(minXCoordinate, i);
        minYCoordinate = min(minYCoordinate, j);
        maxXCoordinate = max(maxXCoordinate, i);
        maxYCoordinate = max(maxYCoordinate, j);

        land[i][j] = 0;
        dfs(land, i + 1, j);
        dfs(land, i - 1, j);
        dfs(land, i, j + 1);
        dfs(land, i, j - 1);
    }

    void resetCoordinates()
    {
        minXCoordinate = INT_MAX;
        minYCoordinate = INT_MAX;
        maxXCoordinate = INT_MIN;
        maxYCoordinate = INT_MIN;
    }
};