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
            int numOnes = countOnes(row);
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

    int countOnes(vector<int> &row)
    {
        int result = 0;

        for (int &num : row)
            if (num == 1)
                result++;

        return result;
    }
};