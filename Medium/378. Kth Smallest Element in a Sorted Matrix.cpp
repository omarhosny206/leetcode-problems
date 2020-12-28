// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (vector<int> row : matrix)
            for (int num : row)
                min_heap.push(num);

        k--;

        while (k--)
            min_heap.pop();

        return min_heap.top();
    }
};