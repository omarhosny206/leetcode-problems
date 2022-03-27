
class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<int> result;
        multimap<int, int> rows;

        int i = 0;
        for (vector<int> &row : mat)
        {
            int numOnes = binarySearch(row);
            rows.insert({numOnes, i++});
        }

        auto iterator = rows.begin();

        while (k--)
            result.push_back(iterator++->second);

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
};