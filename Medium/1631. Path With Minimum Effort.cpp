
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        vector<vector<int>> efforts(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        minHeap.push({0, 0, 0});

        while (!minHeap.empty())
        {
            vector<int> current = minHeap.top();
            minHeap.pop();

            int effort = current[0];
            int row = current[1];
            int column = current[2];

            if (effort > efforts[row][column])
                continue;

            if (row == heights.size() - 1 && column == heights[row].size() - 1)
                return effort;

            for (vector<int> &direction : directions)
            {
                int newRow = row + direction[0];
                int newColumn = column + direction[1];

                if (isValidPosition(heights, newRow, newColumn))
                {
                    int maxEffort = max(effort, abs(heights[row][column] - heights[newRow][newColumn]));

                    if (maxEffort < efforts[newRow][newColumn])
                    {
                        efforts[newRow][newColumn] = maxEffort;
                        minHeap.push({maxEffort, newRow, newColumn});
                    }
                }
            }
        }

        return efforts[heights.size() - 1][heights[0].size() - 1];
    }

    bool isValidPosition(vector<vector<int>> &heights, int i, int j)
    {
        if (i >= heights.size() || i < 0 || j >= heights[i].size() || j < 0)
            return false;

        return true;
    }
};