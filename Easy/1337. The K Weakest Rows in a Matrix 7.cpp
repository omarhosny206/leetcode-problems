// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

class Solution
{
private:
    struct Comparator
    {
        bool operator()(pair<int, int> &firstRow, pair<int, int> &secondRow)
        {
            if (firstRow.first == secondRow.first)
                return firstRow.second < secondRow.second;

            return firstRow.first < secondRow.first;
        }
    };

public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<int> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> maxHeap;

        int i = 0;
        for (vector<int> &row : mat)
        {
            int numOnes = binarySearch(row);
            maxHeap.push({numOnes, i++});

            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        while (!maxHeap.empty())
        {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        reverse(result.begin(), result.end());
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