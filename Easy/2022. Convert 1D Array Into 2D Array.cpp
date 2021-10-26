// https://leetcode.com/problems/convert-1d-array-into-2d-array/

class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        if (!canBeConverted(original, m, n))
            return {};

        vector<vector<int>> result(m, vector<int>(n));
        int i = 0;
        int j = 0;
        int k = 0;

        while (k < original.size())
        {
            result[i][j] = original[k];

            k++;
            j++;

            if (j == n)
            {
                j = 0;
                i++;
            }
        }

        return result;
    }

    bool canBeConverted(vector<int> &original, int m, int n)
    {
        return m * n == original.size();
    }
};