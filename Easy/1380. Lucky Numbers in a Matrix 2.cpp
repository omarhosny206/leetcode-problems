// https://leetcode.com/problems/lucky-numbers-in-a-matrix/

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        vector<int> result;
        unordered_set<int> maxVals;

        for (int j = 0; j < matrix[0].size(); ++j)
        {
            int max = INT_MIN;

            for (int i = 0; i < matrix.size(); i++)
                if (matrix[i][j] > max)
                    max = matrix[i][j];

            maxVals.insert(max);
        }

        for (vector<int> row : matrix)
        {
            int min = INT_MAX;
            for (int num : row)
                if (min > num)
                    min = num;

            if (maxVals.find(min) != maxVals.end())
                result.push_back(min);
        }

        return result;
    }
};