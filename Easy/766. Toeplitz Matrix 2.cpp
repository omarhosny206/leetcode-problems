// https://leetcode.com/problems/toeplitz-matrix/

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        unordered_map<int, int> value;

        for (int r = 0; r < matrix.size(); r++)
        {
            for (int c = 0; c < matrix[0].size(); c++)
            {
                if (value.find(r - c) == value.end())
                    value[r - c] = matrix[r][c];

                else if (value[r - c] != matrix[r][c])
                    return false;
            }
        }

        return true;
    }
};