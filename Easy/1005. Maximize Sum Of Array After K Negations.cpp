// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &A, int K)
    {
        int answer = 0;
        priority_queue<int, vector<int>, greater<int>> min_heap(A.begin(), A.end());

        while (K--)
        {
            int num = min_heap.top();
            min_heap.pop();
            min_heap.push(-1 * num);
        }

        while (!min_heap.empty())
        {
            answer += min_heap.top();
            min_heap.pop();
        }

        return answer;
    }
};