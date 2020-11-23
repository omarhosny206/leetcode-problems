// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<int> result;
        multimap<int, int> mapping;

        int i = 0;
        for (vector<int> row : mat)
        {
            int counter = 0;
            for (int num : row)
                if (num == 1)
                    counter++;

            mapping.emplace(counter, i++);
        }

        auto itr = mapping.begin();

        while (k--)
            result.push_back(itr++->second);

        return result;
    }
};