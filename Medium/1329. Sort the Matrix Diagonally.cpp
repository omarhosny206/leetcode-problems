// https://leetcode.com/problems/sort-the-matrix-diagonally/

class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        for (int i = 0; i < mat[0].size(); ++i)
            sortDiagonal(mat, 0, i);

        for (int i = 1; i < mat.size(); ++i)
            sortDiagonal(mat, i, 0);

        return mat;
    }

    void sortDiagonal(vector<vector<int>> &mat, int row, int column)
    {
        vector<int> diagonal;
        int i = row;
        int j = column;

        while (i < mat.size() && j < mat[i].size())
        {
            diagonal.push_back(mat[i][j]);
            i++;
            j++;
        }

        sort(diagonal.begin(), diagonal.end());

        i = row;
        j = column;
        int k = 0;

        while (i < mat.size() && j < mat[i].size())
        {
            mat[i][j] = diagonal[k];
            i++;
            j++;
            k++;
        }
    }
};