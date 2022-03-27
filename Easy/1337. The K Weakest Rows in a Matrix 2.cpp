// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<int> result;
        vector<pair<int, int>> rows;

        int i = 0;
        for (vector<int> &row : mat)
        {
            int numOnes = countOnes(row);
            rows.push_back({numOnes, i++});
        }

        sort(rows.begin(), rows.end(), compare);

        for (int j = 0; j < k; ++j)
            result.push_back(rows[j].second);

        return result;
    }

    int countOnes(vector<int> &row)
    {
        int result = 0;

        for (int &num : row)
            if (num == 1)
                result++;

        return result;
    }

    static bool compare(pair<int, int> &firstRow, pair<int, int> &secondRow)
    {
        if (firstRow.first == secondRow.first)
            return firstRow.second < secondRow.second;

        return firstRow.first < secondRow.first;
    }
};