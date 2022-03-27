// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

class Solution
{
private:
    struct Comparator
    {
        bool operator()(pair<int, int> &firstRow, pair<int, int> &secondRow)
        {
            if (firstRow.first == secondRow.first)
                return firstRow.second > secondRow.second;

            return firstRow.first > secondRow.first;
        }
    };

public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<int> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> minHeap;

        int i = 0;
        for (vector<int> &row : mat)
        {
            int numOnes = countOnes(row);
            minHeap.push({numOnes, i++});
        }

        while (k--)
        {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

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