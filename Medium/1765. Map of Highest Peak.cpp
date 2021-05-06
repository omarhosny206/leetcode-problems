// https://leetcode.com/problems/map-of-highest-peak/

class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        vector<vector<int>> result(isWater.size(), vector<int>(isWater[0].size(), -1));
        queue<pair<int, int>> cells;

        for (int i = 0; i < isWater.size(); ++i)
        {
            for (int j = 0; j < isWater[i].size(); ++j)
            {
                if (isWater[i][j] == 1)
                {
                    cells.push({i, j});
                    result[i][j] = 0;
                }
            }
        }

        BFS(result, cells);

        return result;
    }

    void BFS(vector<vector<int>> &result, queue<pair<int, int>> &cells)
    {
        int directions[] = {-1, 0, 1, 0, -1};

        while (!cells.empty())
        {

            int i = cells.front().first;
            int j = cells.front().second;
            cells.pop();

            for (int k = 0; k < 4; ++k)
            {
                if (checkBoundaries(result, i + directions[k], j + directions[k + 1]))
                {
                    result[i + directions[k]][j + directions[k + 1]] = result[i][j] + 1;
                    cells.push({i + directions[k], j + directions[k + 1]});
                }
            }
        }
    }

    bool checkBoundaries(vector<vector<int>> &result, int i, int j)
    {
        if (i < 0 || i >= result.size() || j < 0 || j >= result[i].size() || result[i][j] != -1)
            return false;

        return true;
    }
};