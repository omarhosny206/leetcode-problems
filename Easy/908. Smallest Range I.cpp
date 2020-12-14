// https://leetcode.com/problems/smallest-range-i/

class Solution
{
public:
    int smallestRangeI(vector<int> &A, int K)
    {
        int MIN = A[0], MAX = A[0];
        for (int num : A)
        {
            MIN = min(MIN, num);
            MAX = max(MAX, num);
        }
        return max(0, MAX - MIN - 2 * K);
    }
};