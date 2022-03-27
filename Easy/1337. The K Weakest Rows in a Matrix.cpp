// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

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
            int numOnes = countOnes(row);
            rows.insert({numOnes, i++});
        }

        auto iterator = rows.begin();

        while (k--)
            result.push_back(iterator++->second);

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
};