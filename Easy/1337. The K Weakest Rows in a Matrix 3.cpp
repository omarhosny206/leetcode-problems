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
            int binarySearch = countOnes(row);
            rows.push_back({numOnes, i++});
        }

        sort(rows.begin(), rows.end(), compare);

        for (int j = 0; j < k; ++j)
            result.push_back(rows[j].second);

        return result;
    }

    int binarySearch(vector<int> &row)
    {
        int left = 0;
        int right = row.size() - 1;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            if (row[middle] == 0)
                right = middle - 1;

            else
                left = middle + 1;
        }

        return left;
    }

    static bool compare(pair<int, int> &firstRow, pair<int, int> &secondRow)
    {
        if (firstRow.first == secondRow.first)
            return firstRow.second < secondRow.second;

        return firstRow.first < secondRow.first;
    }
};