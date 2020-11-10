// https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        sort(A.begin(), A.end(), cmp);
        for (int i = 0; i < A.size(); i++)
            A[i] = A[i] * A[i];

        return A;
    }

    static bool cmp(int x, int y)
    {
        return x * x < y * y;
    }
};