// https://leetcode.com/problems/pascals-triangle/

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> pascalTriangle(numRows);
        vector<int> current;
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (j == 0 || j == i)
                    pascalTriangle[i].push_back(1);
                else
                    pascalTriangle[i].push_back(pascalTriangle[i - 1][j] + pascalTriangle[i - 1][j - 1]);
            }
        }
        return pascalTriangle;
    }
};