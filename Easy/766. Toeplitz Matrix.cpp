// https://leetcode.com/problems/toeplitz-matrix/

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        unordered_map<int, int> map;
        int rows = matrix.size(), columns = matrix[0].size();

        for (int r = 0; r < rows; r++)
        {

            for (int c = 0; c < columns; c++)
            {

                if (map.find(r - c) == map.end())
                    map.insert({r - c, matrix[r][c]});

                else if (map[r - c] != matrix[r][c])
                    return false;
            }
        }
        return true;
    }
};