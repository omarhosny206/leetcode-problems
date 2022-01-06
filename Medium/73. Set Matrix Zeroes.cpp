// https://leetcode.com/problems/set-matrix-zeroes/

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<pair<int, int>> seen;

        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix[i].size(); ++j)
                if (matrix[i][j] == 0)
                    seen.push_back({i, j});

        for (auto &pair : seen)
            convertToZeroes(matrix, pair.first, pair.second);
    }

    void convertToZeroes(vector<vector<int>> &matrix, int i, int j)
    {
        for (int k = 0; k < matrix.size(); ++k)
            matrix[k][j] = 0;

        for (int k = 0; k < matrix[i].size(); ++k)
            matrix[i][k] = 0;
    }
};